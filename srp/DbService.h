#pragma once

#include <string>
#include "User.h"

class DbService {
public:

    DbService(std::string databaseUrl) : m_databaseUrl(std::move(databaseUrl)) {}
    void saveUser(User const& p_user);

private:
    void connect() {}
    void save(User const& user) {}
    void release() {}

    std::string m_databaseUrl;
};