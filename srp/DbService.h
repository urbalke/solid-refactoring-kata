#ifndef SRP_DBSERVICE_H
#define SRP_DBSERVICE_H


#include <string>
#include "User.h"

class DbService {
public:
    void connect(std::string const& databaseUrl) {}
    void save(User const& user) {}
    void release() {}
};


#endif //SRP_DBSERVICE_H
