#include "mysql_state.h"

#include "../common/Logging.h"
namespace claims {
namespace mysql {
CMysqlState::StObErrorStringMap CMysqlState::maps_[C_MAX_ERROR_CODE] = {};
const CMysqlState CMysqlState::instance_;

CMysqlState::CMysqlState()
{

}

void CMysqlState::C_ADD_SQLSTATE(int oberr, const char *jdbc_state, const char *odbc_state)
{
  if (oberr <= 0)
  {
    maps_[-oberr].jdbc_state = jdbc_state;
    maps_[-oberr].odbc_state = odbc_state;
  }
}

const char *CMysqlState::get_odbc_state(int oberr) const
{
  const char *state = "S1000";
  const char *state_succ = "00000";

  if (oberr <= 0)
  {
    if (oberr == C_SUCCESS)
    {
      state = state_succ;
    }
    else if ((-oberr) >= C_MAX_ERROR_CODE)
    {
      //Logs::log
	MySqlLog("oceanbase error code out of range, err=[%d]", oberr);
    }
    else if (NULL != maps_[-oberr].odbc_state && maps_[-oberr].odbc_state[0] != '\0')
    {
      state = maps_[-oberr].odbc_state;
    }
  }
  return state;
}

const char *CMysqlState::get_jdbc_state(int oberr) const
{
  const char *state = "HY000";
  const char *state_succ = "00000";

  if (oberr <= 0)
  {
    if (oberr == C_SUCCESS)
    {
      state = state_succ;
    }
    else if ((-oberr) >= C_MAX_ERROR_CODE)
    {
      //Logs::log
	MySqlLog("oceanbase error code out of range, err=[%d]", oberr);
    }
    else if (NULL != maps_[-oberr].jdbc_state && maps_[-oberr].jdbc_state[0] != '\0')
    {
      state = maps_[-oberr].jdbc_state;
    }
  }
  return state;
}
}  // namespace mysql
}  // namespace claims
