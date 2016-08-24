/* (C) 2010-2012 Alibaba Group Holding Limited.
 *
 * This program is free software: you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  version 2 as published by the Free Software Foundation.
 *
 * Version: 0.1
 *
 * Authors:
 *    Wu Di <lide.wd@taobao.com>
 */
#include "../mysql_define.h"
#include "mysql_sql_packet.h"

#include "../../common/Logging.h"
#include "../mysql_util.h"


#include "../mysql_server.h"
namespace claims {
namespace mysql {
int MysqlSQLPacket::encode(char* buffer, int64_t length, int64_t& pos)
{

	int ret = C_SUCCESS;
	int64_t start_pos = pos;
	if (NULL == buffer || 0 >= length || pos < 0)
	{
		//Logs::elog
	MySqlElog("invalid argument buffer=%p, length=%ld, pos=%ld",
				buffer, length, pos);
		ret = C_INVALID_ARGUMENT;
	}
	else
	{
		pos += C_MYSQL_PACKET_HEADER_SIZE;
		ret = serialize(buffer, length, pos);
		if (C_SUCCESS == ret)
		{
			uint32_t pkt_len = static_cast<uint32_t>(pos - start_pos - C_MYSQL_PACKET_HEADER_SIZE);

			if (C_SUCCESS != (ret = CMysqlUtil::store_int3(buffer, length, pkt_len, start_pos)))
			{
				//Logs::elog
	MySqlElog("serialize packet haader size failed, buffer=%p, buffer length=%ld, packet length=%d, pos=%ld",
						buffer, length, pkt_len, start_pos);
			}
			else{

			}
				if (C_SUCCESS != (ret = CMysqlUtil::store_int1(buffer, length, header_.seq_, start_pos)))
			{
				//Logs::elog
	MySqlElog("serialize packet haader seq failed, buffer=%p, buffer length=%ld, seq number=%u, pos=%ld",
						buffer, length, header_.seq_, start_pos);
			}
				else{

				}
		}
		else
		{
			if (LIKELY(C_BUF_NOT_ENOUGH == ret || C_SIZE_OVERFLOW == ret))
			{
				//do nothing
			}
			else
			{
				//Logs::elog
	MySqlElog("encode packet data failed, ret is %d", ret);
			}
		}

		if (C_SUCCESS != ret)
		{
			pos = start_pos;
		}
	}
	return ret;
}
}  // namespace mysql
}  // namespace claims
