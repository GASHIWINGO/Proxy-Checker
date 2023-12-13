#include "checker.h"

static size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct* mem = (struct MemoryStruct*)userp;

    char* ptr = (char*)realloc(mem->memory, mem->size + realsize + 1);
    if (ptr == NULL) {
        // memory alloc error
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

bool checkProxy(const std::string& ip, int port, const std::string& targetURL, double& responseTime, std::string type, std::string& username, std::string& password) {
    CURL* curl = curl_easy_init();
    struct MemoryStruct chunk;
    chunk.memory = (char*)malloc(1);
    chunk.size = 0;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_PROXY, ip.c_str());
        curl_easy_setopt(curl, CURLOPT_PROXYPORT, port);
        curl_easy_setopt(curl, CURLOPT_URL, targetURL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

        double totalTime;

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        if (type == "SOCKS4") { curl_easy_setopt(curl, CURLOPT_PROXYTYPE, CURLPROXY_SOCKS4); }

        if (type == "SOCKS5") { curl_easy_setopt(curl, CURLOPT_PROXYTYPE, CURLPROXY_SOCKS5); }

        if (!username.empty() && !password.empty()) {
            std::string proxyAuth = username + ":" + password;
            curl_easy_setopt(curl, CURLOPT_PROXYUSERPWD, proxyAuth.c_str());
        }

        CURLcode res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            // time response
            curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &totalTime);
            responseTime = totalTime;
        }

        curl_easy_cleanup(curl);
        free(chunk.memory);

        return res == CURLE_OK;
    }

    return false;
}

void checkProxyInfo(const std::string& ip, int port, const std::string& key, std::ofstream& outputFile, bool http, bool socks4, bool socks5, bool non_working, std::string& username, std::string& password) {

    CURL* curl = curl_easy_init();
    struct MemoryStruct chunk;
    chunk.memory = (char*)malloc(1);
    chunk.size = 0;

    if (curl) {
        std::string url = "http://proxycheck.io/v2/" + ip + "?key=" + key + "&asn=1";
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);

        CURLcode res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            rapidjson::Document doc;
            doc.Parse(chunk.memory);

            if (!doc.HasParseError() && doc.HasMember("status")) {
                if (doc[ip.c_str()].HasMember("isocode") && doc[ip.c_str()].HasMember("type")) {
                    std::string country = doc[ip.c_str()]["isocode"].GetString();
                    std::string proxyType = doc[ip.c_str()]["type"].GetString();

                    std::string status;

                    double responseTime;
                    if ((http && (proxyType == "HTTP" || proxyType == "HTTPS" || proxyType == "Business")) ||
                        (socks4 && proxyType == "SOCKS4") ||
                        (socks5 && proxyType == "SOCKS5")) {

                        bool isWorking = checkProxy(ip, port, "http://proxy-checker.net/api/proxy-checker/", responseTime, proxyType, username, password);

                        if (isWorking) {
                            status = "Valid";
                        }
                        else {
                            status = "Invalid";
                        }

                        if (isWorking || non_working) {
                            if (!username.empty() && !password.empty()) {
                                outputFile << status << " " << ip << ":" << port << " " << username << " " << password << " " << responseTime << " " << country << "\n";
                            }
                            else {
                                outputFile << status << " " << ip << ":" << port << " ---" << " ---"<< " " << responseTime << " " << country << "\n";
                            }
                        }
                    }
                    else {
                        std::cerr << "Wrong proxy type for " << ip << ":" << port << std::endl;
                    }
                }
                else {
                    std::cerr << "Required information is missing for " << ip << ":" << port << std::endl;
                }
            }
            else {
                std::cerr << "Error parsing IP information for " << ip << ":" << port << std::endl;
            }
        }
        else {
            std::cerr << "Error when requesting proxycheck.io for " << ip << ":" << port << std::endl;
        }

        curl_easy_cleanup(curl);
        free(chunk.memory);
    }
}

bool start(bool http, bool socks4, bool socks5, bool non_working) {
    setlocale(0, "");

    std::ifstream proxyFile("proxy_list.txt");

    std::string key = "yb0r04-06c337-0644n8-750231";

    std::string outputFileName = "proxy_info.txt";

    std::ofstream outputFile(outputFileName.c_str());

    if (!proxyFile.is_open()) {
        std::cerr << "Cannot open file with proxy servers" << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Cannot open file to write proxy info" << std::endl;
        proxyFile.close();
        return 1;
    }

    std::string proxy;

    std::regex ipPattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    std::regex portPattern("^[0-9]{1,5}$");

    while (std::getline(proxyFile, proxy)) {
        std::string ip = "";
        int port = 0;
        std::string username = "";
        std::string password = "";

        size_t colonCount = std::count(proxy.begin(), proxy.end(), ':');
        if (colonCount == 1 || colonCount == 3) {
            ip = proxy.substr(0, proxy.find(':'));
            std::string rest = proxy.substr(proxy.find(':') + 1);

            if (std::regex_match(ip, ipPattern) && (colonCount == 1 && std::regex_match(rest, portPattern) || colonCount == 3 && std::regex_match(rest.substr(0, rest.find(':')), portPattern))) {
                if (colonCount == 1) {
                    port = std::stoi(rest);
                }
                else if (colonCount == 3) {
                    port = std::stoi(rest.substr(0, rest.find(':')));
                    username = rest.substr(rest.find(':') + 1, rest.rfind(':') - rest.find(':') - 1);
                    password = rest.substr(rest.rfind(':') + 1);
                }

                checkProxyInfo(ip, port, key, outputFile, http, socks4, socks5, non_working, username, password);
            }
        }
    }

    proxyFile.close();
    outputFile.close();

    return 1;
}