#pragma once

#include <string>
#include <stdexcept>
#include "DbService.h"
#include "SmtpClient.h"
#include "Email.hpp"
#include "Password.hpp"
#include "DatabaseUrl.hpp"

class UserManager {
public:
    UserManager(DatabaseUrl, std::vector<SmtpClientParameter>);
    void registerUser(Email, Password);

private:
    DbService db;
    SmtpClient smtp;
};