#ifndef C_MYSQL_DEFINE_H_
#define C_MYSQL_DEFINE_H_

#include <stdint.h>
#include <sys/types.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <openssl/md5.h>

namespace claims {
namespace mysql {
#define LIKELY(x)       __builtin_expect(!!(x),1)


//typedef signed char		int8_t;
//typedef short int			int16_t;
//typedef int					int32_t;
//# if __WORDSIZE == 64
//typedef long int			int64_t;
//# else
//__extension__
//typedef long long int	int64_t;
//#endif

const int64_t TIMEOUT= 30 * 3600L;	// timeout is 30 minutes
const int64_t EPOLLTIMEOUT = 1000;	// epoll timeout
const int64_t MAX_PACKET_SIZE = 2 * 1024 * 1024L;	//packet size

const int C_ERR_FULL_SESSION = -5059;

////////////////////////////////////////////////////////////
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define UINT16_MAX	(65535U)
#define UINT64_MAX	123413334

const int C_SUCCESS = EXIT_SUCCESS;
const int C_ERROR = EXIT_FAILURE;

const uint16_t C_COMPACT_COLUMN_INVALID_ID = UINT16_MAX;
const uint64_t C_INVALID_ID = UINT64_MAX;

const int C_INVALID_INDEX = -1;
const int64_t C_INVALID_VERSION = -1;
const int64_t C_MAX_ITERATOR = 16;
const int64_t MAX_IP_ADDR_LENGTH = 32;
const int64_t MAX_IP_PORT_LENGTH = MAX_IP_ADDR_LENGTH + 5;

//////////////////////////////////////////////////////////////// begin ob error code
//error code for common -1 ---- -1000
const int C_OBJ_TYPE_ERROR = -1;
const int C_INVALID_ARGUMENT = -2;
const int C_ARRAY_OUT_OF_RANGE = -3;
const int C_SERVER_LISTEN_ERROR = -4;
const int C_INIT_TWICE = -5;
const int C_NOT_INIT = -6;
const int C_NOT_SUPPORTED = -7;
const int C_ITER_END = -8;
const int C_IO_ERROR = -9;
const int C_ERROR_FUNC_VERSION = -10;
const int C_PACKET_NOT_SENT = -11;
const int C_RESPONSE_TIME_OUT = -12;
const int C_ALLOCATE_MEMORY_FAILED = -13;
const int C_MEM_OVERFLOW = -14;
const int C_ERR_SYS = -15;
const int C_ERR_UNEXPECTED = -16;
const int C_ENTRY_EXIST = -17;
const int C_ENTRY_NOT_EXIST = -18;
const int C_SIZE_OVERFLOW = -19;
const int C_REF_NUM_NOT_ZERO = -20;
const int C_CONFLICT_VALUE = -21;
const int C_ITEM_NOT_SETTED = -22;
const int C_EAGAIN = -23;
const int C_BUF_NOT_ENOUGH = -24;
const int C_PARTIAL_FAILED = -25;
const int C_READ_NOTHING = -26;
const int C_FILE_NOT_EXIST = -27;
const int C_DISCONTINUOUS_LOG = -28;
const int C_SCHEMA_ERROR = -29;
const int C_DATA_NOT_SERVE = -30;       // not host this data
const int C_UNKNOWN_OBJ = -31;
const int C_NO_MONITOR_DATA = -32;
const int C_SERIALIZE_ERROR = -33;
const int C_DESERIALIZE_ERROR = -34;
const int C_AIO_TIMEOUT = -35;
const int C_NEED_RETRY = -36; // need retry
const int C_TOO_MANY_SSTABLE = -37;
const int C_NOT_MASTER = -38; // !!! don't modify this value, C_NOT_MASTER = -38
const int C_TOKEN_EXPIRED = -39;
const int C_ENCRYPT_FAILED = -40;
const int C_DECRYPT_FAILED = -41;
const int C_USER_NOT_EXIST = -42;
const int C_PASSWORD_WRONG = -43;
const int C_SKEY_VERSION_WRONG = -44;
const int C_NOT_A_TOKEN = -45;
const int C_NO_PERMISSION = -46;
const int C_COND_CHECK_FAIL = -47;
const int C_NOT_REGISTERED = -48;
const int C_PROCESS_TIMEOUT = -49;
const int C_NOT_THE_OBJECT = -50;
const int C_ALREADY_REGISTERED = -51;
const int C_LAST_LOG_RUINNED = -52;
const int C_NO_CS_SELECTED = -53;
const int C_NO_TABLETS_CREATED = -54;
const int C_INVALID_ERROR = -55;
const int C_CONN_ERROR = -56;
const int C_DECIMAL_OVERFLOW_WARN = -57;
const int C_DECIMAL_UNLEGAL_ERROR = -58;
const int C_OBJ_DIVIDE_BY_ZERO = -59;
const int C_OBJ_DIVIDE_ERROR = -60;
const int C_NOT_A_DECIMAL = -61;
const int C_DECIMAL_PRECISION_NOT_EQUAL = -62;
const int C_EMPTY_RANGE = -63; // get emptry range
const int C_SESSION_KILLED = -64;
const int C_LOG_NOT_SYNC = -65;
const int C_DIR_NOT_EXIST = -66;
const int C_NET_SESSION_END = -67;
const int C_INVALID_LOG = -68;
const int C_FOR_PADDING = -69;
const int C_INVALID_DATA = -70;
const int C_ALREADY_DONE = -71;
const int C_CANCELED = -72;
const int C_LOG_SRC_CHANGED = -73;
const int C_LOG_NOT_ALIGN = -74;
const int C_LOG_MISSING = -75;
const int C_NEED_WAIT = -76;
const int C_NOT_IMPLEMENT = -77;
const int C_DIVISION_BY_ZERO = -78;
const int C_VALUE_OUT_OF_RANGE = -79;
const int C_EXCEED_MEM_LIMIT = -80;
const int C_RESULT_UNKNOWN = -81;
const int C_ERR_DATA_FORMAT = -82;
const int C_MAYBE_LOOP = -83;
const int C_NO_RESULT= -84;
const int C_QUEUE_OVERFLOW = -85;
const int C_START_LOG_CURSOR_INVALID = -99;
const int C_LOCK_NOT_MATCH = -100;
const int C_DEAD_LOCK = -101;
const int C_PARTIAL_LOG = -102;
const int C_CHECKSUM_ERROR = -103;
const int C_INIT_FAIL = -104;
const int C_ASYNC_CLIENT_WAITING_RESPONSE = -108;
const int C_STATE_NOT_MATCH = -109;
const int C_READ_ZERO_LOG = -110;
const int C_SWITCH_LOG_NOT_MATCH = -111;
const int C_LOG_NOT_START = -112;
const int C_IN_FATAL_STATE = -113;
const int C_IN_STOP_STATE = -114;
const int C_UPS_MASTER_EXISTS = -115;
const int C_LOG_NOT_CLEAR = -116;
const int C_FILE_ALREADY_EXIST = -117;
const int C_UNKNOWN_PACKET = -118;
const int C_TRANS_ROLLBACKED = -119;
const int C_LOG_TOO_LARGE = -120;

const int C_RPC_SEND_ERROR = -121;
const int C_RPC_POST_ERROR = -122;
const int C_LIBEASY_ERROR = -123;
const int C_CONNECT_ERROR = -124;
const int C_NOT_FREE = -125;
const int C_INIT_SQL_CONTEXT_ERROR = -126;
const int C_SKIP_INVALID_ROW = -127;

const int C_SYS_CONFIG_TABLE_ERROR = -131;
const int C_READ_CONFIG_ERROR = -132;

const int C_TRANS_NOT_MATCH = -140;
const int C_TRANS_IS_READONLY = -141;
const int C_ROW_MODIFIED = -142;
const int C_VERSION_NOT_MATCH = -143;
const int C_BAD_ADDRESS = -144;
const int C_DUPLICATE_COLUMN = -145;
const int C_ENQUEUE_FAILED= -146;
const int C_INVALID_CONFIG = -147;
const int C_WAITING_COMMIT = -148;
const int C_STMT_EXPIRED = -149;
const int C_DISCARD_PACKET = -150;


//error code for chunk server -1001 ---- -2000
const int C_CS_CACHE_NOT_HIT = -1001;   // 缓存没有命中
const int C_CS_TIMEOUT = -1002;         // 超时
const int C_CS_TABLET_NOT_EXIST = -1008; // tablet not exist
const int C_CS_EMPTY_TABLET = -1009;     // tablet has no data.
const int C_CS_EAGAIN = -1010;           //重试

const int C_GET_NEXT_COLUMN = -1011;
const int C_GET_NEXT_ROW = -1012; // for internal use, scan next row.
//const int C_DESERIALIZE_ERROR = -1013;//反序列化失败
const int C_INVALID_ROW_KEY = -1014;//不合法的rowKey
const int C_SEARCH_MODE_NOT_IMPLEMENT = -1015; // search mode not implement, internal error
const int C_INVALID_BLOCK_INDEX = -1016; // illegal block index data, internal error
const int C_INVALID_BLOCK_DATA = -1017;  // illegal block data, internal error
const int C_SEARCH_NOT_FOUND = -1018;    // value not found? for cs_get
const int C_BEYOND_THE_RANGE = -1020;    // search key or range not in current tablet
const int C_CS_COMPLETE_TRAVERSAL = -1021; //complete traverse block cache
const int C_END_OF_ROW = -1022;
const int C_CS_MERGE_ERROR = -1024;
const int C_CS_SCHEMA_INCOMPATIBLE = -1025;
const int C_CS_SERVICE_NOT_STARTED = -1026;
const int C_CS_LEASE_EXPIRED = -1027;
const int C_CS_MERGE_HAS_TIMEOUT = -1028;
const int C_CS_TABLE_HAS_DELETED = -1029;
const int C_CS_MERGE_CANCELED = -1030;
const int C_CS_COMPRESS_LIB_ERROR = -1031;
const int C_CS_OUTOF_DISK_SPACE = -1032;
const int C_CS_MIGRATE_IN_EXIST = -1033;
const int C_AIO_BUF_END_BLOCK = -1034;
const int C_AIO_EOF = -1035;
const int C_AIO_BUSY = -1036;
const int C_WRONG_SSTABLE_DATA = -1037;
const int C_COLUMN_GROUP_NOT_FOUND = -1039;
const int C_NO_IMPORT_SSTABLE = -1040;
const int C_IMPORT_SSTABLE_NOT_EXIST = -1041;

//error code for update server -2001 ---- -3000
const int C_UPS_TRANS_RUNNING = -2001;     // 事务正在执行
const int C_FREEZE_MEMTABLE_TWICE = -2002; // memtable has been frozen
const int C_DROP_MEMTABLE_TWICE = -2003;   // memtable has been dropped
const int C_INVALID_START_VERSION = -2004; // memtable start version invalid
const int C_UPS_NOT_EXIST = -2005;         // not exist
const int C_UPS_ACQUIRE_TABLE_FAIL = -2006;// acquire table via version fail
const int C_UPS_INVALID_MAJOR_VERSION = -2007;
const int C_UPS_TABLE_NOT_FROZEN = -2008;
const int C_UPS_CHANGE_MASTER_TIMEOUT = -2009;
const int C_FORCE_TIME_OUT = -2010;
const int C_BEGIN_TRANS_LOCKED = -2011;

//error code for root server -3001 ---- -4000
const int C_ERROR_TIME_STAMP = -3001;
const int C_ERROR_INTRESECT = -3002;
const int C_ERROR_OUT_OF_RANGE = -3003;
const int C_RS_STATUS_INIT = -3004;
const int C_IMPORT_NOT_IN_SERVER = -3005;
const int C_FIND_OUT_OF_RANGE = -3006;
const int C_CONVERT_ERROR = -3007;
const int C_MS_ITER_END = -3008;
const int C_MS_NOT_EXIST = -3009;
const int C_BYPASS_TIMEOUT = -3010;
const int C_BYPASS_DELETE_DONE = -3011;
const int C_RS_STATE_NOT_ALLOW = -3012;
const int C_BYPASS_NEED_REPORT = -3014;
const int C_ROOT_TABLE_CHANGED = -3015;
const int C_ROOT_REPLICATE_NO_DEST_CS_FOUND = -3016;
const int C_ROOT_TABLE_RANGE_NOT_EXIST = -3017;
const int C_ROOT_MIGRATE_CONCURRENCY_FULL = -3018;
const int C_ROOT_MIGRATE_INFO_NOT_FOUND = -3019;
const int C_NOT_DATA_LOAD_TABLE = -3020;
const int C_DATA_LOAD_TABLE_DUPLICATED = -3021;
const int C_ROOT_TABLE_ID_EXIST = -3022;
const int C_CLUSTER_ALREADY_MASTER = -3023;
const int C_IP_PORT_IS_NOT_SLAVE_CLUSTER = -3024;
const int C_CLUSTER_IS_NOT_SLAVE = -3025;
const int C_CLUSTER_IS_NOT_MASTER = -3026;
const int C_CONFIG_NOT_SYNC = -3027;
const int C_IP_PORT_IS_NOT_CLUSTER = -3028;
const int C_MASTER_CLUSTER_NOT_EXIST = -3029;
const int C_CLUSTER_INFO_NOT_EXIST = -3030;
const int C_GET_CLUSTER_MASTER_UPS_FAILED = -3031;
const int C_MULTIPLE_MASTER_CLUSTERS_EXIST = -3032;
const int C_MULTIPLE_MASTER_CLUSTERS_NOT_EXIST = -3033;
const int C_MASTER_CLUSTER_ALREADY_EXISTS = -3034;
const int C_CREATE_TABLE_TWICE = -3035;

const int C_DATA_SOURCE_NOT_EXIST = -3100;
const int C_DATA_SOURCE_TABLE_NOT_EXIST = -3101;
const int C_DATA_SOURCE_RANGE_NOT_EXIST = -3102;
const int C_DATA_SOURCE_DATA_NOT_EXIST = -3103;
const int C_DATA_SOURCE_SYS_ERROR = -3104;
const int C_DATA_SOURCE_TIMEOUT = -3105;
const int C_DATA_SOURCE_CONCURRENCY_FULL = -3106;
const int C_DATA_SOURCE_WRONG_URI_FORMAT = -3107;
const int C_SSTABLE_VERSION_UNEQUAL = -3108;
const int C_DATA_SOURCE_READ_ERROR = -3109;
const int C_ROOT_MIGRATE_INFO_EXIST = -3110;
const int C_ROOT_RANGE_NOT_CONTINUOUS = -3111;
const int C_DATA_SOURCE_TABLET_VERSION_ERROR = -3112;
const int C_DATA_LOAD_TABLE_STATUS_ERROR = -3113;

//error code for merge server -4000 ---- -5000
const int C_INNER_STAT_ERROR = -4001;     // inner stat check error
const int C_OLD_SCHEMA_VERSION = -4002;   // find old schema version
const int C_INPUT_PARAM_ERROR = -4003;    // check input param error
const int C_NO_EMPTY_ENTRY = -4004;       // not find empty entry
const int C_RELEASE_SCHEMA_ERROR = -4005; // release schema error
const int C_ITEM_COUNT_ERROR = -4006;     // fullfill item count error
const int C_OP_NOT_ALLOW = -4007;         // fetch new schema not allowed
const int C_CHUNK_SERVER_ERROR = -4008;   // chunk server cached is error
const int C_NO_NEW_SCHEMA = -4009;        // no new schema when parse error
const int C_MS_SUB_REQ_TOO_MANY = -4010; // too many sub scan request
const int C_TOO_MANY_BLOOM_FILTER_TASK = -4011;

// SQL specific error code, -5000 ~ -6000
const int C_ERR_SQL_START = -5000;
const int C_ERR_PARSER_INIT = -5000;
const int C_ERR_PARSE_SQL = -5001;
const int C_ERR_RESOLVE_SQL = -5002;
const int C_ERR_GEN_PLAN = -5003;
const int C_ERR_UNKNOWN_SYS_FUNC = -5004;
const int C_ERR_PARSER_MALLOC_FAILED = -5005;
const int C_ERR_PARSER_SYNTAX = -5006;
const int C_ERR_COLUMN_SIZE = -5007;
const int C_ERR_COLUMN_DUPLICATE = -5008;
const int C_ERR_COLUMN_UNKNOWN = -5009;
const int C_ERR_OPERATOR_UNKNOWN = -5010;
const int C_ERR_STAR_DUPLICATE = -5011;
const int C_ERR_ILLEGAL_ID = -5012;
const int C_ERR_WRONG_POS = -5013;
const int C_ERR_ILLEGAL_VALUE = -5014;
const int C_ERR_COLUMN_AMBIGOUS = -5015;
const int C_ERR_LOGICAL_PLAN_FAILD = -5016;
const int C_ERR_SCHEMA_UNSET = -5017;
const int C_ERR_ILLEGAL_NAME = -5018;
const int C_ERR_TABLE_UNKNOWN = -5019;
const int C_ERR_TABLE_DUPLICATE = -5020;
const int C_ERR_NAME_TRUNCATE = -5021;
const int C_ERR_EXPR_UNKNOWN = -5022;
const int C_ERR_ILLEGAL_TYPE = -5023;
const int C_ERR_PRIMARY_KEY_DUPLICATE = -5024;
const int C_ERR_ALREADY_EXISTS = -5025;
const int C_ERR_CREATETIME_DUPLICATE = -5026;
const int C_ERR_MODIFYTIME_DUPLICATE = -5027;
const int C_ERR_ILLEGAL_INDEX = -5028;
const int C_ERR_INVALID_SCHEMA = -5029;
const int C_ERR_INSERT_NULL_ROWKEY = -5030; // SQLSTATE '23000'
const int C_ERR_COLUMN_NOT_FOUND = -5031;   // SQLSTATE '42S22'
const int C_ERR_DELETE_NULL_ROWKEY = -5032;
const int C_ERR_INSERT_INNER_JOIN_COLUMN = -5033;
const int C_ERR_USER_EMPTY = -5034;
const int C_ERR_USER_NOT_EXIST = -5035;
const int C_ERR_NO_PRIVILEGE = -5036;
const int C_ERR_NO_AVAILABLE_PRIVILEGE_ENTRY = -5037;
const int C_ERR_WRONG_PASSWORD = -5038;
const int C_ERR_USER_IS_LOCKED = -5039;
const int C_ERR_UPDATE_ROWKEY_COLUMN = -5040;
const int C_ERR_UPDATE_JOIN_COLUMN = -5041;
const int C_ERR_INVALID_COLUMN_NUM = -5042; // SQLSTATE 'S1002'
const int C_ERR_PREPARE_STMT_UNKNOWN = -5043; // SQLSTATE 'HY007'
const int C_ERR_VARIABLE_UNKNOWN = -5044;
const int C_ERR_SESSION_INIT = -5045;
const int C_ERR_OLDER_PRIVILEGE_VERSION = -5046;
const int C_ERR_LACK_OF_ROWKEY_COL = -5047;
const int C_ERR_EXCLUSIVE_LOCK_CONFLICT = -5048;
const int C_ERR_SHARED_LOCK_CONFLICT = -5049;
const int C_ERR_USER_EXIST = -5050;
const int C_ERR_PASSWORD_EMPTY = -5051;
const int C_ERR_GRANT_PRIVILEGES_TO_CREATE_TABLE = -5052;
const int C_ERR_WRONG_DYNAMIC_PARAM = -5053; // SQLSTATE '07001'
const int C_ERR_PARAM_SIZE = -5054;
const int C_ERR_FUNCTION_UNKNOWN = -5055;
const int C_ERR_CREAT_MODIFY_TIME_COLUMN = -5056;
const int C_ERR_MODIFY_PRIMARY_KEY = -5057;
const int C_ERR_PARAM_DUPLICATE = -5058;
const int C_ERR_TOO_MANY_SESSIONS = -5059;
const int C_ERR_TRANS_ALREADY_STARTED = -5060;
const int C_ERR_TOO_MANY_PS = -5061;
const int C_ERR_NOT_IN_TRANS = -5062;
const int C_ERR_HINT_UNKNOWN = -5063;
const int C_ERR_WHEN_UNSATISFIED = -5064;
const int C_ERR_QUERY_INTERRUPTED = -5065;
const int C_ERR_SESSION_INTERRUPTED = -5066;
const int C_ERR_UNKNOWN_SESSION_ID = -5067;
const int C_ERR_PROTOCOL_NOT_RECOGNIZE = -5068;
const int C_ERR_WRITE_AUTH_ERROR = -5069; //write auth packet to client failed 来自监控的连接会立马断开
const int C_ERR_PARSE_JOIN_INFO = -5070;

const int C_ERR_PS_TOO_MANY_PARAM = -5080;
const int C_ERR_READ_ONLY = -5081;

const int C_ERR_SQL_END = -5999;
#define IS_SQL_ERR(e) ((C_ERR_SQL_END <= e && C_ERR_SQL_START >= e) \
		|| C_ERR_EXCLUSIVE_LOCK_CONFLICT == e \
		|| C_ERR_SHARED_LOCK_CONFLICT == e)

// Fatal errors and the client should close the connection, -8000 ~ -8999
const int C_ERR_SERVER_IN_INIT = -8001;
const int C_PACKET_CHECKSUM_ERROR = -8002;
//////////////////////////////////////////////////////////////// end of ob error code

typedef int64_t    ObDateTime;
typedef int64_t    ObPreciseDateTime;
typedef ObPreciseDateTime ObModifyTime;
typedef ObPreciseDateTime ObCreateTime;

const int64_t C_MAX_SQL_LENGTH = 10240;
const int64_t C_SQL_LENGTH = 1024;
const int64_t C_MAX_URI_LENGTH = 1024;
const int64_t C_MAX_SERVER_ADDR_SIZE = 128;
const uint64_t C_MAX_VALID_COLUMN_ID = 10240;   // user table max valid column id
const int64_t C_MAX_TABLE_NUMBER = 2048;
const int64_t C_MAX_JOIN_INFO_NUMBER = 10;
const int64_t C_MAX_ROW_KEY_LENGTH = 16384; // 16KB
const int64_t C_MAX_ROW_KEY_SPLIT = 32;
const int64_t C_MAX_ROWKEY_COLUMN_NUMBER = 16;
const int64_t C_MAX_COLUMN_NAME_LENGTH = 128;  //this means we can use 127 chars for a name.
const int64_t C_MAX_APP_NAME_LENGTH = 128;
const int64_t C_MAX_DATA_SOURCE_NAME_LENGTH = 128;
const int64_t C_MAX_YUNTI_USER_LENGTH = 128;
const int64_t C_MAX_YUNTI_GROUP_LENGTH = 128;
const int64_t C_MAX_INSTANCE_NAME_LENGTH = 128;
const int64_t C_MAX_HOST_NAME_LENGTH = 128;
const int64_t C_MAX_MS_TYPE_LENGTH = 10;

const int64_t C_MAX_DEBUG_MSG_LEN = 1024;
const int64_t C_MAX_COMPRESSOR_NAME_LENGTH = 128;
const int64_t C_MAX_TABLE_NAME_LENGTH = 256;
const int64_t C_MAX_FILE_NAME_LENGTH = 512;
const int64_t C_MAX_SECTION_NAME_LENGTH = 128;
const int64_t C_MAX_FLAG_NAME_LENGTH = 128;
const int64_t C_MAX_FLAG_VALUE_LENGTH = 512;
const int64_t C_MAX_TOKEN_BUFFER_LENGTH = 80;
const int64_t C_MAX_PACKET_LENGTH = 1<<21; // max packet length, 2MB
const int64_t C_MAX_ROW_NUMBER_PER_QUERY = 65536;
const int64_t C_MAX_BATCH_NUMBER = 100;
const int64_t C_MAX_TABLET_LIST_NUMBER = 1<<10;
const int64_t C_MAX_DISK_NUMBER = 16;
const int64_t C_MAX_TIME_STR_LENGTH = 64;
const int64_t C_IP_STR_BUFF = 30;
const int64_t C_RANGE_STR_BUFSIZ = 512;
const int64_t C_MAX_FETCH_CMD_LENGTH = 2048;
const int64_t C_MAX_EXPIRE_CONDITION_LENGTH = 512;
const int64_t C_MAX_TABLE_COMMENT_LENGTH = 512;
const int64_t C_MAX_COLUMN_GROUP_NUMBER = 16;
const int64_t C_MAX_THREAD_READ_SSTABLE_NUMBER = 16;
const int64_t C_MAX_GET_ROW_NUMBER = 10240;
const uint64_t C_FULL_ROW_COLUMN_ID = 0;
const uint64_t C_DELETE_ROW_COLUMN_ID = 0;
const int64_t C_DIRECT_IO_ALIGN_BITS = 9;
const int64_t C_DIRECT_IO_ALIGN = 1<<C_DIRECT_IO_ALIGN_BITS;
const int64_t C_MAX_COMPOSITE_SYMBOL_COUNT = 256;
const int64_t C_SERVER_VERSION_LENGTH = 64;
const int64_t C_SERVER_TYPE_LENGTH = 64;
const int64_t C_MAX_USERNAME_LENGTH = 32;
const int64_t C_MAX_PASSWORD_LENGTH = 32;
const int64_t C_MAX_CIPHER_LENGTH = MD5_DIGEST_LENGTH * 2;

const int64_t C_MAX_RESULT_MESSAGE_LENGTH = 1024;
const int64_t C_MAX_LOG_BUFFER_SIZE = 1966080L;  // 1.875MB

const int32_t C_SAFE_COPY_COUNT = 3;
const int32_t C_DEC_AND_LOCK = 2626; /* used by remoe_plan in ObPsStore */
// OceanBase Log Synchronization Type
const int64_t C_LOG_NOSYNC = 0;
const int64_t C_LOG_SYNC = 1;
const int64_t C_LOG_DELAYED_SYNC = 2;
const int64_t C_LOG_NOT_PERSISTENT = 4;

//const int64_t C_MAX_UPS_LEASE_DURATION_US = INT64_MAX;

const int64_t C_EXECABLE = 1;
const int64_t C_WRITEABLE = 2;
const int64_t C_READABLE = 4;
const int64_t C_SCHEMA_START_VERSION = 100;
const int64_t C_SYS_PARAM_ROW_KEY_LENGTH = 192;
const int64_t C_MAX_SYS_PARAM_NAME_LENGTH = 128;

const int64_t C_MAX_PREPARE_STMT_NUM_PER_SESSION = 512;
const int64_t C_MAX_VAR_NUM_PER_SESSION = 1024;
const int64_t C_DEFAULT_SESSION_TIMEOUT = 100L * 1000L * 1000L; // 10s
const int64_t C_DEFAULT_STMT_TIMEOUT = 3L * 1000L * 1000L; // 1s
const int64_t C_DEFAULT_INTERNAL_TABLE_QUERY_TIMEOUT = 10L * 1000L * 1000L; // 10s
static const int64_t CORE_SCHEMA_VERSION = 1984;
static const int64_t CORE_TABLE_COUNT = 3;

//Oceanbase network protocol
/*  4bytes    4bytes        4bytes       4bytes
 * -------------------------------------------------
 * | flag | channel id | packet code | data length |
 * -------------------------------------------------
 */
const int C_TBNET_HEADER_LENGTH = 16;  //16 bytes packet header

const int C_TBNET_PACKET_FLAG = 0x416e4574;
const int C_SERVER_ADDR_STR_LEN = 128; //used for buffer size of easy_int_addr_to_str

/*   3bytes   1 byte
 * ------------------
 * |   len  |  seq  |
 * ------------------
 */
const int C_MYSQL_PACKET_HEADER_SIZE = 4; /** 3bytes length + 1byte seq*/

const int64_t C_UPS_START_MAJOR_VERSION = 2;
const int64_t C_UPS_START_MINOR_VERSION = 1;

const int64_t C_NEWEST_DATA_VERSION = -2;

const int32_t C_CONNECTION_FREE_TIME_S = 900;

/// @see C_object.cpp and C_expr_obj.cpp
static const float FLOAT_EPSINON = static_cast<float>(1e-6);
static const double DOUBLE_EPSINON = 1e-14;

const uint64_t C_UPS_MAX_MINOR_VERSION_NUM = 2048;
const int64_t C_MAX_COMPACTSSTABLE_NUM = 64;

enum ObRole
{
	C_INVALID = 0,
	C_ROOTSERVER = 1,  // rs
	C_CHUNKSERVER = 2, // cs
	C_MERGESERVER = 3, // ms
	C_UPDATESERVER = 4,// ups
	C_PROXYSERVER = 5,
};

static const int C_FAKE_MS_PORT = 2828;
static const uint64_t C_MAX_PS_PARAM_COUNT = 65535;
static const uint64_t C_MAX_PS_FIELD_COUNT = 65535;
static const uint64_t C_ALL_MAX_COLUMN_ID = 65535;
// internal columns id
const uint64_t C_NOT_EXIST_COLUMN_ID = 0;
const uint64_t C_CREATE_TIME_COLUMN_ID = 2;
const uint64_t C_MODIFY_TIME_COLUMN_ID = 3;
const uint64_t C_DEFAULT_COLUMN_GROUP_ID = 0;
const int64_t C_END_RESERVED_COLUMN_ID_NUM = 16;
const uint64_t C_APP_MIN_COLUMN_ID = 16;
const uint64_t C_ACTION_FLAG_COLUMN_ID = C_ALL_MAX_COLUMN_ID - C_END_RESERVED_COLUMN_ID_NUM + 1; /* 65520 */
const uint64_t C_MAX_TMP_COLUMN_ID = C_ALL_MAX_COLUMN_ID - C_END_RESERVED_COLUMN_ID_NUM;
// internal columns name
//extern const char *C_CREATE_TIME_COLUMN_NAME;
//extern const char *C_MODIFY_TIME_COLUMN_NAME;
static const char * const CLUSTER_ID_FILE = "etc/cluster.id";

// internal tables name
const char* const FIRST_TABLET_TABLE_NAME = "__first_tablet_entry";
const char* const C_ALL_COLUMN_TABLE_NAME = "__all_all_column";
const char* const C_ALL_JOININFO_TABLE_NAME = "__all_join_info";
const char* const C_ALL_SERVER_STAT_TABLE_NAME = "__all_server_stat";
const char* const C_ALL_SYS_PARAM_TABLE_NAME = "__all_sys_param";
const char* const C_ALL_SYS_CONFIG_TABLE_NAME = "__all_sys_config";
const char* const C_ALL_SYS_STAT_TABLE_NAME = "__all_sys_stat";
const char* const C_ALL_USER_TABLE_NAME = "__all_user";
const char* const C_ALL_TABLE_PRIVILEGE_TABLE_NAME = "__all_table_privilege";
const char* const C_ALL_TRIGGER_EVENT_TABLE_NAME= "__all_trigger_event";
const char* const C_ALL_SYS_CONFIG_STAT_TABLE_NAME = "__all_sys_config_stat";
const char* const C_ALL_SERVER_SESSION_TABLE_NAME = "__all_server_session";
const char* const C_ALL_CLUSTER = "__all_cluster";
const char* const C_ALL_SERVER = "__all_server";
const char* const C_ALL_CLIENT = "__all_client";
const char* const C_TABLES_SHOW_TABLE_NAME = "__tables_show";
const char* const C_VARIABLES_SHOW_TABLE_NAME = "__variables_show";
const char* const C_CREATE_TABLE_SHOW_TABLE_NAME = "__create_table_show";
const char* const C_TABLE_STATUS_SHOW_TABLE_NAME = "__table_status_show";
const char* const C_SCHEMA_SHOW_TABLE_NAME = "__schema_show";
const char* const C_COLUMNS_SHOW_TABLE_NAME = "__columns_show";
const char* const C_SERVER_STATUS_SHOW_TABLE_NAME = "__server_status_show";
const char* const C_PARAMETERS_SHOW_TABLE_NAME = "__parameters_show";
const char* const C_ALL_STATEMENT_TABLE_NAME = "__all_statement";

// internal params
const char* const C_GROUP_AGG_PUSH_DOWN_PARAM = "C_group_agg_push_down_param";
const char* const C_QUERY_TIMEOUT_PARAM = "C_query_timeout";
const char* const C_READ_CONSISTENCY = "C_read_consistency";

///////////////////////////////////////////////////////////
//                 SYSTEM TABLES                         //
///////////////////////////////////////////////////////////
// SYTEM TABLES ID (0, 500), they should not be mutated
static const uint64_t C_NOT_EXIST_TABLE_TID = 0;
static const uint64_t C_FIRST_META_VIRTUAL_TID = C_INVALID_ID - 1; // not a real table
static const uint64_t C_FIRST_TABLET_ENTRY_TID = 1;
static const uint64_t C_ALL_ALL_COLUMN_TID = 2;
static const uint64_t C_ALL_JOIN_INFO_TID = 3;
static const uint64_t C_ALL_SYS_PARAM_TID = 4;
static const uint64_t C_ALL_SYS_STAT_TID = 5;
static const uint64_t C_USERS_TID = 6;
static const uint64_t C_TABLE_PRIVILEGES_TID = 7;
static const uint64_t C_ALL_CLUSTER_TID = 8;
static const uint64_t C_ALL_SERVER_TID = 9;
static const uint64_t C_TRIGGER_EVENT_TID = 10;
static const uint64_t C_ALL_SYS_CONFIG_TID = 11;
static const uint64_t C_ALL_SYS_CONFIG_STAT_TID = 12;
static const uint64_t C_ALL_CLIENT_TID = 13;
///////////////////////////////////////////////////////////
//                 VIRUTAL TABLES                        //
///////////////////////////////////////////////////////////
// VIRTUAL TABLES ID (500, 700), they should not be mutated
#define IS_VIRTUAL_TABLE(tid) ((tid) > 500 && (tid) < 700)
static const uint64_t C_TABLES_SHOW_TID = 501;
static const uint64_t C_COLUMNS_SHOW_TID = 502;
static const uint64_t C_VARIABLES_SHOW_TID = 503;
static const uint64_t C_TABLE_STATUS_SHOW_TID = 504;
static const uint64_t C_SCHEMA_SHOW_TID = 505;
static const uint64_t C_CREATE_TABLE_SHOW_TID = 506;
static const uint64_t C_PARAMETERS_SHOW_TID = 507;
static const uint64_t C_SERVER_STATUS_SHOW_TID = 508;
static const uint64_t C_ALL_SERVER_STAT_TID = 509;
static const uint64_t C_ALL_SERVER_SESSION_TID = 510;
static const uint64_t C_ALL_STATEMENT_TID = 511;
#define IS_SHOW_TABLE(tid) ((tid) >= C_TABLES_SHOW_TID && (tid) <= C_SERVER_STATUS_SHOW_TID)
///////////////////////////////////////////////////////////
//                 USER TABLES                           //
///////////////////////////////////////////////////////////
// USER TABLE ID (1000, MAX)
static const uint64_t C_APP_MIN_TABLE_ID = 1000;
inline bool IS_SYS_TABLE_ID(uint64_t tid) {return (tid < C_APP_MIN_TABLE_ID);};

static const uint64_t C_ALL_STAT_COLUMN_MAX_COLUMN_ID = 45;
static const uint64_t C_ALL_ALL_COLUMN_MAX_COLUMN_ID = 45;
static const uint64_t C_ALL_JOIN_INFO_MAX_COLUMN_ID = 45;
static const uint64_t C_ALL_SYS_STAT_MAX_COLUMN_ID = 45;
static const uint64_t C_ALL_SYS_PARAM_MAX_COLUMN_ID = 45;
static const uint64_t C_ALL_SYS_CONFIG_MAX_COLUMN_ID = 45;
static const uint64_t C_ALL_CLUSTER_MAX_COLUMN_ID = 45;
static const uint64_t C_ALL_SERVER_MAX_COLUMN_ID = 45;

static const uint64_t C_MAX_CLUSTER_NAME = 128;
static const uint64_t C_MAX_CLUSTER_INFO = 128;
static const int64_t C_MAX_CLUSTER_COUNT = 6;
// internal user id
static const uint64_t C_ADMIN_UID = 1;
const char* const C_ADMIN_USER_NAME = "admin";

// C_malloc & C_tc_malloc
static const int64_t C_TC_MALLOC_BLOCK_HEADER_SIZE = 64; // >= sizeof(TSIBlockCache::Block)
static const int64_t C_MALLOC_BLOCK_SIZE = 64*1024LL+1024LL;
static const int64_t C_TC_MALLOC_BLOCK_SIZE = C_MALLOC_BLOCK_SIZE - C_TC_MALLOC_BLOCK_HEADER_SIZE;

/// 一个行可以包含的最大元素/列数
static const int64_t C_ROW_MAX_COLUMNS_COUNT = 512; // used in ObRow
static const int64_t C_MAX_VARCHAR_LENGTH = 64 * 1024;
static const int64_t C_COMMON_MEM_BLOCK_SIZE = C_MAX_VARCHAR_LENGTH;
static const int64_t C_MAX_ROW_LENGTH = C_MAX_PACKET_LENGTH - 512L * 1024L;
static const int64_t C_MAX_COLUMN_NUMBER = C_ROW_MAX_COLUMNS_COUNT; // used in ObSchemaManagerV2
static const int64_t C_MAX_USER_DEFINED_COLUMNS_COUNT = C_ROW_MAX_COLUMNS_COUNT - C_APP_MIN_COLUMN_ID;

static const int64_t C_PREALLOCATED_NUM = 21;

const char* const SYS_DATE = "$SYS_DATE";
const char* const C_DEFAULT_COMPRESS_FUNC_NAME = "none";

static const int64_t C_MAX_CONFIG_NAME_LEN = 64;
static const int64_t C_MAX_CONFIG_VALUE_LEN = 1024;
static const int64_t C_MAX_CONFIG_INFO_LEN = 1024;
static const int64_t C_MAX_CONFIG_NUMBER = 1024;
static const int64_t C_MAX_EXTRA_CONFIG_LENGTH = 4096;

static const int64_t C_TABLET_MAX_REPLICA_COUNT = 6;

const char* const C_META_TABLE_NAME_PREFIX = "__m_";
static const int64_t C_META_TABLE_NAME_PREFIX_LENGTH = strlen(C_META_TABLE_NAME_PREFIX);

static const int64_t C_DEFAULT_SSTABLE_BLOCK_SIZE = 16*1024; // 16KB
static const int64_t C_DEFAULT_MAX_TABLET_SIZE = 256*1024*1024; // 256MB
static const int64_t C_MYSQL_PACKET_BUFF_SIZE = 6 * 1024; //6KB
static const int64_t C_MAX_ERROR_MSG_LEN = 128;
static const int64_t C_MAX_ERROR_CODE = 10000;
static const int64_t C_MAX_THREAD_NUM = 1024;
static const int64_t C_CHAR_SET_NAME_LENGTH = 16;

enum ObDmlType
{
	C_DML_UNKNOW   = 0,
	C_DML_REPLACE  = 1,
	C_DML_INSERT   = 2,
	C_DML_UPDATE   = 3,
	C_DML_DELETE   = 4,
	C_DML_NUM,
};

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
		TypeName(const TypeName&);               \
		void operator=(const TypeName&)

// 对于 serialize 函数 pos既是输入参数又是输出参数，
// serialize把序列化的数据从(buf+pos)处开始写入，
// 写入完成后更新pos。如果写入后的数据要超出(buf+buf_len)，
// serialize返回失败。
//
// 对于 deserialize 函数 pos既是输入参数又是输出参数，
// deserialize从(buf+pos)处开始地读出数据进行反序列化，
// 完成后更新pos。如果反序列化所需数据要超出(buf+data_len)，
// deserialize返回失败。

#define NEED_SERIALIZE_AND_DESERIALIZE \
		int serialize(char* buf, const int64_t buf_len, int64_t& pos) const; \
		int deserialize(const char* buf, const int64_t data_len, int64_t& pos); \
		int64_t get_serialize_size(void) const

#define INLINE_NEED_SERIALIZE_AND_DESERIALIZE \
		inline int serialize(char* buf, const int64_t buf_len, int64_t& pos) const; \
		inline int deserialize(const char* buf, const int64_t data_len, int64_t& pos); \
		inline int64_t get_serialize_size(void) const

#define VIRTUAL_NEED_SERIALIZE_AND_DESERIALIZE \
		virtual int serialize(char* buf, const int64_t buf_len, int64_t& pos) const; \
		virtual int deserialize(const char* buf, const int64_t data_len, int64_t& pos); \
		virtual int64_t get_serialize_size(void) const

#define PURE_VIRTUAL_NEED_SERIALIZE_AND_DESERIALIZE \
		virtual int serialize(char* buf, const int64_t buf_len, int64_t& pos) const = 0; \
		virtual int deserialize(const char* buf, const int64_t data_len, int64_t& pos) = 0; \
		virtual int64_t get_serialize_size(void) const = 0

#define DEFINE_SERIALIZE(TypeName) \
		int TypeName::serialize(char* buf, const int64_t buf_len, int64_t& pos) const


#define DEFINE_DESERIALIZE(TypeName) \
		int TypeName::deserialize(const char* buf, const int64_t data_len, int64_t& pos)

#define DEFINE_GET_SERIALIZE_SIZE(TypeName) \
		int64_t TypeName::get_serialize_size(void) const
#ifndef UNUSED
#define UNUSED(v) ((void)(v))
#endif

#define DATABUFFER_SERIALIZE_INFO \
		data_buffer_.get_data(), data_buffer_.get_capacity(), data_buffer_.get_position()

#define C_LIKELY(x)       __builtin_expect(!!(x),1)
#define C_UNLIKELY(x)     __builtin_expect(!!(x),0)

#define ARRAYSIZEOF(a) (sizeof(a)/sizeof(a[0]))

#define C_ASSERT(x) do{ if(!(x)) TBSYS_LOG(ERROR, "assert fail, exp=%s", #x); assert(x);} while(false)

#define ATOMIC_CAS(val, cmpv, newv) __sync_val_compare_and_swap((val), (cmpv), (newv))
#define ATOMIC_ADD(val, addv) __sync_add_and_fetch((val), (addv))
#define ATOMIC_SUB(val, subv) __sync_sub_and_fetch((val), (subv))
#define ATOMIC_INC(val) __sync_add_and_fetch((val), 1)
#define ATOMIC_DEC(val) __sync_sub_and_fetch((val), 1)
#define __COMPILER_BARRIER() asm volatile("" ::: "memory")
#define PAUSE() asm("pause\n")


#define CACHE_ALIGN_SIZE 64
#define CACHE_ALIGNED __attribute__((aligned(CACHE_ALIGN_SIZE)))
#define DIO_ALIGN_SIZE 512


#define C_STAT_INC(module, args...) \
		do { \
			ObStatManager *mgr = ObStatSingleton::get_instance(); \
			if (NULL != mgr) { mgr->inc(C_STAT_##module, 0/*table id*/, ##args); } \
		}while(0)


#define C_STAT_SET(module, args...) \
		do { \
			ObStatManager *mgr = ObStatSingleton::get_instance(); \
			if (NULL != mgr) { mgr->set_value(C_STAT_##module, 0, /* table id */ ##args); } \
		}while(0)


#define C_STAT_GET(module, args...) \
		do { \
			ObStatManager *mgr = ObStatSingleton::get_instance(); \
			if (NULL != mgr) { mgr->get_stat(C_STAT_##module, 0, ##args); } \
		}while(0)

#define C_STAT_GET_VALUE(module, type) \
		({ \
			int64_t ret = 0; \
			ObStatManager *mgr = ObStatSingleton::get_instance(); \
			ObStat *stat = NULL; \
			if (NULL != mgr) { mgr->get_stat(C_STAT_##module, 0, stat); } \
			if (NULL != stat) { ret = stat->get_value(type);} \
			ret; \
		})

#define C_STAT_TABLE_INC(module, table_id, args...) \
		do { \
			ObStatManager *mgr = ObStatSingleton::get_instance(); \
			if (NULL != mgr) { mgr->inc(C_STAT_##module,(table_id), ##args); } \
		}while(0)



#define C_STAT_TABLE_SET(module, table_id, args...) \
		do { \
			ObStatManager *mgr = ObStatSingleton::get_instance(); \
			if (NULL != mgr) { mgr->set_value(C_STAT_##module, (table_id), ##args); } \
		}while(0)


#define C_STAT_TABLE_GET(module, table_id, args...) \
		do { \
			ObStatManager *mgr = ObStatSingleton::get_instance(); \
			if (NULL != mgr) { mgr->get_stat(C_STAT_##module, (table_id), ##args); } \
		}while(0)


#ifdef __ENABLE_PRELOAD__
#include "C_preload.h"
#endif


/////////////////////////////////////////////////////////////

#define int1store(T,A)       do { *((uint8_t *)(T)) = (uint8_t)(A); } while (0)
#define int2store(T,A)       do { uint def_temp= (uint) (A) ;   \
		*((uint8_t*) (T))=  (uint8_t)(def_temp);                    \
		*((uint8_t*) (T)+1)=(uint8_t)((def_temp >> 8));             \
} while(0)
#define int3store(T,A)       do { /*lint -save -e734 */ \
*((uint8_t*)(T))=(uint8_t) ((A));                   \
*((uint8_t*) (T)+1)=(uint8_t) (((A) >> 8));         \
*((uint8_t*)(T)+2)=(uint8_t) (((A) >> 16));         \
/*lint -restore */} while(0)
#define int4store(T,A)       do { *((char *)(T))=(char) ((A));  \
		*(((char *)(T))+1)=(char) (((A) >> 8));                     \
		*(((char *)(T))+2)=(char) (((A) >> 16));                    \
		*(((char *)(T))+3)=(char) (((A) >> 24)); } while(0)
#define int8store(T,A)       do { uint def_temp= (uint) (A), def_temp2= (uint) ((A) >> 32); \
		int4store((T),def_temp);                                            \
		int4store((T+4),def_temp2); } while(0)

#define uint3korr(A)	(uint32_t) (((uint32_t) ((uint8_t) (A)[0])) +   \
		(((uint32_t) ((uint8_t) (A)[1])) << 8) + \
		(((uint32_t) ((uint8_t) (A)[2])) << 16))
#define uint4korr(A)	(uint32_t) (((uint32_t) ((uint8_t) (A)[0])) +   \
		(((uint32_t) ((uint8_t) (A)[1])) << 8) + \
		(((uint32_t) ((uint8_t) (A)[2])) << 16) + \
		(((uint32_t) ((uint8_t) (A)[3])) << 24))
#define uint1korr(A)    (*((uint8_t *)A))
enum enum_server_command
{
 COM_SLEEP, COM_QUIT, COM_INIT_DB, COM_QUERY, COM_FIELD_LIST,
 COM_CREATE_DB, COM_DROP_DB, COM_REFRESH, COM_SHUTDOWN, COM_STATISTICS,
 COM_PROCESS_INFO, COM_CONNECT, COM_PROCESS_KILL, COM_DEBUG, COM_PING,
 COM_TIME, COM_DELAYED_INSERT, COM_CHANGE_USER, COM_BINLOG_DUMP, COM_TABLE_DUMP,
 COM_CONNECT_OUT, COM_REGISTER_SLAVE, COM_STMT_PREPARE, COM_STMT_EXECUTE, COM_STMT_SEND_LONG_DATA,
 COM_STMT_CLOSE, COM_STMT_RESET, COM_SET_OPTION, COM_STMT_FETCH, COM_DAEMON,
 COM_END/*30*/, COM_DELETE_SESSION    /* COM_DELETE_SESSION 不是标准的mysql包类型 这个是用来处理删除session的包
                                    在连接断开的时候，需要删除session 但是此时有可能在回调函数disconnect中获取不到
                                    session的锁，此时会往obmysql的队列中添加一个异步任务*/
};
}  // namespace mysql
}  // namespace claims


#endif
