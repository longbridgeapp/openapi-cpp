//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/11.
//

/**
 * @file logger.h
 * @brief 日志帮助函数
 */

#ifndef LONGBRIDGE_OPENSDK_LOGGER_H
#define LONGBRIDGE_OPENSDK_LOGGER_H

#include "logger.rs.h"
#include "logger_format.h"

#define _COL(x) "\033[" #x ";1m"
#define _RED _COL(31)
#define _GREEN _COL(32)
#define _YELLOW _COL(33)
#define _GRAY "\033[0m"

#define LOCAL_VAR(name) __##name##__

// log one line max char 2048
#ifdef _WIN32
#define _LOG_IMP(with_name, ...)                                     \
  struct CStringType {                                               \
    const char* chars = __FILE__;                                    \
  };                                                                 \
  bool LOCAL_VAR(_with_name) = (with_name);                          \
  ::logger::ParamNameList LOCAL_VAR(_name_list)({});                   \
  std::string LOCAL_VAR(_format)(::logger::Format(                     \
      LOCAL_VAR(_with_name), LOCAL_VAR(_name_list), ##__VA_ARGS__)); \
  char buf[2048] = {0};
#else
#define _LOG_IMP(with_name, ...)                                       \
  struct CStringType {                                                 \
    const char* chars = __FILE__;                                      \
  };                                                                   \
  bool LOCAL_VAR(_with_name) = (with_name);                            \
  ::logger::ParamNameList LOCAL_VAR(_name_list)(ARG_NAMES(__VA_ARGS__)); \
  std::string LOCAL_VAR(_format)(::logger::Format(                       \
      LOCAL_VAR(_with_name), LOCAL_VAR(_name_list), ##__VA_ARGS__));   \
  char buf[2048] = {0};
#endif

#define _LOG_ERR_IMP(with_name, ...)                                        \
  do {                                                                      \
    _LOG_IMP(with_name, ##__VA_ARGS__)                                      \
    sprintf(buf, _RED "ERR:%s(%d):%s:" _GRAY " %s\n",                       \
            ::logger::CompileTimeCal::TGetFileName<sizeof(__FILE__),          \
                                                 CStringType>::name::chars, \
            __LINE__, __func__, LOCAL_VAR(_format).c_str());                \
    ::logger::log_error_internal(buf);                                        \
  } while (0)

#define _LOG_WARN_IMP(with_name, ...)                                       \
  do {                                                                      \
    _LOG_IMP(with_name, ##__VA_ARGS__)                                      \
    sprintf(buf, _YELLOW "ERR:%s(%d):%s:" _GRAY " %s\n",                    \
            ::logger::CompileTimeCal::TGetFileName<sizeof(__FILE__),          \
                                                 CStringType>::name::chars, \
            __LINE__, __func__, LOCAL_VAR(_format).c_str());                \
    ::logger::log_warn_internal(buf);                                         \
  } while (0)

#define _LOG_DEBUG_IMP(with_name, ...)                                      \
  do {                                                                      \
    _LOG_IMP(with_name, ##__VA_ARGS__)                                      \
    sprintf(buf, _GREEN "ERR:%s(%d):%s:" _GRAY " %s\n",                     \
            ::logger::CompileTimeCal::TGetFileName<sizeof(__FILE__),          \
                                                 CStringType>::name::chars, \
            __LINE__, __func__, LOCAL_VAR(_format).c_str());                \
    ::logger::log_debug_internal(buf);                                        \
  } while (0)

#ifdef _WIN32
#define LOG_ERR(...) _LOG_ERR_IMP(false, ##__VA_ARGS__)
#define LOG_DEBUG(...) _LOG_DEBUG_IMP(false, ##__VA_ARGS__)
#define LOG_WARN(...) _LOG_WARN_IMP(false, ##__VA_ARGS__)
#else
/**
 * @brief ERR log level, LOG_ERR("example", a);
 * output: example a value_of_a
 */
#define LOG_ERR(...) _LOG_ERR_IMP(true, ##__VA_ARGS__)
/**
 * @brief DEBUG log level, same as LOG_ERR
 */
#define LOG_DEBUG(...) _LOG_DEBUG_IMP(true, ##__VA_ARGS__)
/**
 * @brief WARN log level, same as LOG_ERR
 */
#define LOG_WARN(...) _LOG_WARN_IMP(true, ##__VA_ARGS__)
#endif

#endif  // LONGBRIDGE_OPENSDK_LOGGER_H
