#ifndef SRP_DBSERVICE_H
#define SRP_DBSERVICE_H


#include <string>
#include "User.h"

class DbService {
public:
    void saveUser(User const& p_user);

private:
    void connect(std::string const& databaseUrl) {}
    void save(User const& user) {}
    void release() {}

    std::string m_databaseUrl = "postgres-host:database-name";
};


#endif //SRP_DBSERVICE_H
