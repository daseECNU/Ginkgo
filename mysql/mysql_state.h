/*
 * (C) 2007-2012 Taobao Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Version: $id
 *
 * Authors:
 *   fufeng <fufeng.syd@taobao.com>
 *     - some work details if you want
 */

#ifndef _C_MYSQL_STATE_H_
#define _C_MYSQL_STATE_H_
#include "mysql_define.h"
namespace claims {
namespace mysql {
class CMysqlState {
 public:
  struct StObErrorStringMap {
    const char *jdbc_state;
    const char *odbc_state;
  };
 public:
  /**
   * @return single instance referrence
   */
  static const CMysqlState& get_instance() {
    return instance_;
  }
  /**
   * 返回odbc sqlstate
   *
   * @param oberr oceanbase error code
   *
   * @return 1. 大于0和未定义的转换返回通用错误「S1000」
   *         2. 等于0则返回「00000」表示成功
   *         3. 其余则返回在maps中定义的sqlstate
   */
  const char* get_odbc_state(int oberr) const;
  /**
   * 返回jdbc sqlstate
   *
   * @param oberr oceanbase error code
   *
   * @return 1. 大于0和未定义的转换返回通用错误「HY000」
   *         2. 等于0则返回「00000」表示成功
   *         3. 其余则返回在maps中定义的sqlstate
   */
  const char* get_jdbc_state(int oberr) const;
 private:
  /**
   * 添加一个OB error code到sqlstate的映射，忽略大于零的errcode。
   *
   * @param oberr oceanbase error code
   * @param jdbc_state jdbc sqlstate
   * @param odbc_state odbc sqlstate
   */
  void C_ADD_SQLSTATE(int oberr, const char *jdbc_state,
                      const char *odbc_state);
  CMysqlState();
  CMysqlState(const CMysqlState &);
 private:
  static StObErrorStringMap maps_[C_MAX_ERROR_CODE];
  static const CMysqlState instance_;
};
}  // namespace mysql
}  // namespace claims
#endif /* _C_MYSQL_STATE_H_ */
