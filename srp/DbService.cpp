#include "DbService.h"

void DbService::saveUser(User const& p_user)
{
    connect(m_databaseUrl);
    save(p_user);
    release();
}