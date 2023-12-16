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

void checkProxyInfo(const std::string& ip, int port, const std::string& key, bool http, bool socks4, bool socks5, bool non_working, std::string& username, std::string& password, std::ofstream& outputFile, bool& isWrite) {

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

                    double responseTime = 0;
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

                            //add info in DB after check 
                            insert_checked_servers(ip, port, status, responseTime, country, username, password);

                            if (!username.empty() && !password.empty()) {
                                outputFile << status << " " << ip << ":" << port << " " << username << " " << password << " " << responseTime << " " << country << "\n";
                                isWrite = true;
                            }
                            else {
                                outputFile << status << " " << ip << ":" << port << " ---" << " ---"<< " " << responseTime << " " << country << "\n";
                                isWrite = true;
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

bool start(bool http, bool socks4, bool socks5, bool non_working, bool& isWrite) {

    std::ofstream outputFile("result.txt");

    //api key
    std::string key = "yb0r04-06c337-0644n8-750231";

    //read list from DB
    read_servers(key, http, socks4, socks5, non_working, outputFile, isWrite);

    if (!outputFile.is_open()) {
        std::cerr << "Cannot open file to write proxy info" << std::endl;
        outputFile.close();
        return 1;
    }

    outputFile.close();

    return 1;
}