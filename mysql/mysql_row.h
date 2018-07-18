/*
 * mysql_row.h
 *
 *  Created on: Dec 6, 2015
 *      Author: ccccly
 */

#ifndef MYSQL_MYSQL_ROW_H_
#define MYSQL_MYSQL_ROW_H_
#include <string>

#include "../common/data_type.h"
#include "../common/Schema/Schema.h"
namespace claims {
namespace mysql {
class MysqlRow {
 public:
  MysqlRow();
  virtual ~MysqlRow();
  /**
   * 将该行数据序列化成MySQL认识的格式，输出位置：buf + pos，执行后pos指向buf中第一个free的位置。
   *
   * @param [in] buf 序列化以后输出的序列的空间
   * @param [in] len buf的长度
   * @param [out] pos 当前buf第一个free的位置
   *
   * @return 成功返回OB_SUCCESS， 失败返回oceanbase error code
   */
  int serialize(char* buffer, int64_t length, int64_t& pos);
  virtual uint64_t get_serialize_size();
  /**
   * 序列化一个cell到buf + pos的位置。
   *
   * @param [in] obj 需要序列化的cell
   * @param [in] buf 输出的buf
   * @param [in] len buf的大小
   * @param [in,out] pos 写入buf的位置
   * @param [in] cell index for binary protocol
   *
   * @return 成功返回OB_SUCCESS， 失败返回oceanbase error code
   */
  int cell_str(const column_type &obj, char *buf, const int64_t len, int64_t &pos,
               int64_t cell_index) const;
  /**
   * 序列化一个null类型的cell到buf + pos的位置。
   *
   * @param [in] obj 需要序列化的cell
   * @param [in] buf 输出的buf
   * @param [in] len buf的大小
   * @param [in,out] pos 写入buf的位置
   * @param [in] field index
   *
   * @return 成功返回OB_SUCCESS， 失败返回oceanbase error code
   */
  int null_cell_str(const column_type &obj, char *buf, const int64_t len,
                    int64_t &pos, int64_t cell_index) const;
  /**
   * 序列化一个整型的cell到buf + pos的位置。
   * (ObBoolType, ObIntType)
   *
   * @param [in] obj 需要序列化的cell
   * @param [in] buf 输出的buf
   * @param [in] len buf的大小
   * @param [in,out] pos 写入buf的位置
   *
   * @return 成功返回OB_SUCCESS， 失败返回oceanbase error code
   */
  int anything_but_null_cell_str(const column_type &obj, char *buf, const int64_t len,
                   int64_t &pos, int64_t cell_index) const;



 public:
  void* tuple_;
  int64_t column_num_;
  Schema* schema_;
};
}  // namespace mysql
}  // namespace claims



#endif /* MYSQL_MYSQL_ROW_H_ */
