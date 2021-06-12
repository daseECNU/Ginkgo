# Add Return Code

## 1. Naming
According to constant names , return code names use a letter 'r' followed by words with upper case first letters.For example:
```  c++
const int rOpenHdfsFileFail = -87;
const int rReadDiskFileFail = -88;
const int rOpenDiskFileFail = -89;
```
> Note: When declaring a function please use RetCode as the function type. Because we have defined RetCode as int in file "./common/error_define.h".

## 2. Code Number
We have several types of error in file "./common/error_define.h". So please add return code number at the proper position.
Besides, please ensure the  number and significance are not repeated.
For example:

``` c++
/* errorno for SQL parser -1001 ~ -2000  */
const int rInitSQLParserErr = -1001;
const int rSQLParserErr = -1002;
/* errorno for codegen -3001 ~ -4000 */
const int rTestError = -3001;
/* errorno for logical_operator -4001 ~ -5000*/
const int rUninitializedJoinPolicy = -4001;
const int rGeneratePlanContextFailed = -4002;
/* errorno for physical_operator -5001 ~ -6000 */
const int rGenerateSubPhyPlanFailed = -5001;
const int rNoPartitionIdScan = -5002;

```

## 3. Return Code Information
Once you add a new return code number, you should add Return Code Message in file "./common/error_no.cpp | ./common/error_no.h" at the same time.
``` c++
  DefineErrorAndMessage(rInvalidArgument, "Invalid argument");
  DefineErrorAndMessage(rArrayOutOfRange, "Array index out of range");
```

## 4. Use macro definition
We have defined some macro to help you to output log. 

```c++
#define ELOG(ret, err_info)                                              \
  LOG(ERROR) << "[" << ret << ", " << CStrError(ret) << "] " << err_info \
             << std::endl;

#define WLOG(ret, warning_info)                                                \
  LOG(WARNING) << "[" << ret << ", " << CStrError(ret) << "] " << warning_info \
               << std::endl;

#define EXEC_AND_ONLY_LOG_ERROR(ret, f, err_info) \
  do {                                            \
    if (rSuccess != (ret = f)) {                  \
      ELOG(ret, err_info)                         \
    }                                             \
  } while (0)

#define EXEC_AND_LOG(ret, f, info, err_info) \
  do {                                       \
    if (rSuccess == (ret = f)) {             \
      LOG(INFO) << info << std::endl;        \
    } else {                                 \
      ELOG(ret, err_info)                    \
    }                                        \
  } while (0)

#define EXEC_AND_PLOG(ret, f, info, err_info)                       \
  do {                                                              \
    if (rSuccess == (ret = f)) {                                    \
      LOG(INFO) << info << std::endl;                               \
    } else {                                                        \
      PLOG(ERROR) << "[ " << ret << ", " << CStrError(ret) << " ] " \
                  << err_info << std::endl;                         \
    }                                                               \
  } while (0)
```

