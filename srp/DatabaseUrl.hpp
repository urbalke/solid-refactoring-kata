#pragma once

#include <string>

class DatabaseUrl
{
public:
    DatabaseUrl(std::string p_databaseUrl) : m_databaseUrl(std::move(p_databaseUrl)) {}

private:
    std::string m_databaseUrl;
};