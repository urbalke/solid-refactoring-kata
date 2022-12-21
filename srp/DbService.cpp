#include "DbService.h"

void DbService::saveUser(User const& p_user)
{
    connect();
    save(p_user);
    release();
}