#pragma once

#include "DB.h"

#define CURL_STATICLIB
#include <curl/curl.h>

#include "rapidjson/document.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

struct MemoryStruct {
    char* memory;
    size_t size;
};

bool start(bool http, bool socks4, bool socks5, bool non_working, bool& isWrite);

static size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp);

bool checkProxy(const std::string& ip, int port, const std::string& targetURL, double& responseTime, std::string type, std::string& username, std::string& password);

void checkProxyInfo(const std::string& ip, int port, const std::string& key, bool http, bool socks4, bool socks5, bool non_working, std::string& username, std::string& password, std::ofstream& outputFile, bool& isWrite);