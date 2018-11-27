#ifndef SRP_USER_H
#define SRP_USER_H


#include <string>
#include <chrono>

struct User {
    std::string email;
    std::string password;
    std::chrono::time_point<std::chrono::system_clock> created;
};


#endif //SRP_USER_H
