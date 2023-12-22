#include "DB.h"

void add_user()
{
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("proxy_checker.db", &DB);

    std::string sql("INSERT INTO User (login_date) VALUES (datetime('now', 'localtime'));");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error add_user" << std::endl;
        std::cout << messaggeError;
    }

    else
        std::cout << "Success add_user" << std::endl;

    sqlite3_close(DB);
}

void add_server(std::string ip_port, std::string login, std::string password)
{
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("proxy_checker.db", &DB);

    std::string sql("INSERT INTO Proxy_servers (IP_Port, login, password, user_id) "
                    "VALUES ('" + ip_port + "', '" + login + "', '" + password + "',(SELECT MAX(user_id) FROM User));");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error add_server" << std::endl;
        std::cout << messaggeError;
    }

    else
        std::cout << "Success add_server" << std::endl;

    sqlite3_close(DB);
}

void read_servers(std::string key, bool http, bool socks4, bool socks5, bool non_working, bool& isWrite)
{
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("proxy_checker.db", &DB);

    std::string sql = "SELECT ps.IP_Port, ps.login, ps.password "
        "FROM Proxy_servers ps "
        "JOIN User u ON ps.user_id = u.user_id "
        "WHERE u.user_id = (SELECT MAX(user_id) FROM User)";

    sqlite3_stmt* stmt;
    std::vector<std::tuple<std::string, std::string, std::string>> data;

    if (sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {

            std::string proxy = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            std::string username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            std::string password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

            data.push_back(std::make_tuple(proxy, username, password));
        }
    }
    sqlite3_close(DB);

    for (const auto& item : data) {
        std::string proxy = std::get<0>(item);
        std::string username = std::get<1>(item);
        std::string password = std::get<2>(item);

        std::string ip = proxy.substr(0, proxy.find(':'));
        std::string rest = proxy.substr(proxy.find(':') + 1);
        int port = std::stoi(rest);

        //pass all parameters to the check function
        checkProxyInfo(ip, port, key, http, socks4, socks5, non_working, username, password, isWrite);
    }
}


void insert_checked_servers(const std::string& ip, int port, const std::string& status, double responsetime, const std::string& country, const std::string& username, const std::string& password) {
    sqlite3* db;
    int exit = sqlite3_open("proxy_checker.db", &db);

    std::string sql = "insert into checked_proxy_servers (status, ip_port, login, password, response_time, country, server_id) "
        "values (?, ?, ?, ?, ?, ?, "
        "(select server_id from proxy_servers where ip_port = ? and user_id = (select max(user_id) from user)))";

    std::string port1 = std::to_string(port);

    std::string ip_port = ip + ":" + port1;

    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, status.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, ip_port.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 5, responsetime);
    sqlite3_bind_text(stmt, 6, country.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, ip_port.c_str(), -1, SQLITE_STATIC);

    int rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE) {
        std::cerr << "Error insert" << sqlite3_errmsg(db) << std::endl;
    }
    else {
        std::cout << "Success insert" << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

std::vector<std::vector<std::string>> read_checked_servers()
{
    sqlite3* db;
    int rc = sqlite3_open("proxy_checker.db", &db);

    std::string sql = "SELECT cps.status, cps.ip_port, cps.login, cps.password, cps.response_time, cps.country, cps.server_id "
        "FROM checked_proxy_servers cps "
        "JOIN Proxy_servers ps ON cps.server_id = ps.server_id "
        "JOIN User u ON ps.user_id = u.user_id "
        "WHERE u.user_id = (SELECT MAX(user_id) FROM User)";

    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        std::cout << "Failed to fetch data: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return {};
    }

    std::vector<std::vector<std::string>> data;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); i++)
        {
            row.push_back(std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i))));
        }
        data.push_back(row);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return data;
}