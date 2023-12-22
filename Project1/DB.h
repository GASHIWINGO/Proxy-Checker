#pragma once

#include "checker.h"

#include "sqlite/sqlite3.h"
#include <string>
#include <iostream>
#include <tuple>
#include <vector>

void add_user();

void add_server(std::string ip_port, std::string login, std::string password);

void read_servers(std::string key, bool http, bool socks4, bool socks5, bool non_working, bool& isWrite);

void insert_checked_servers(const std::string& ip, int port, const std::string& status, double responseTime, const std::string& country, const std::string& username, const std::string& password);

std::vector<std::vector<std::string>> read_checked_servers();