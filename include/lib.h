//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/13.
//

/**
 * @mainpage lb-openapi-cpp
 * @author wenda.jiang@longbridge.sg
 *
 * This is Longbridge OpenAPI SDK-cpp Project.
 *
 * You can use this SDK request Longbridge Server API by Http Or Websocket.
 */

/**
 * @file lib.h
 * @brief SDK 的初始化
 */

#ifndef LONGBRIDGE_OPENAPI_INCLUDE_ENGINE_H_
#define LONGBRIDGE_OPENAPI_INCLUDE_ENGINE_H_
#include "lib.rs.h"
namespace longbridge {
/**
 * @brief 初始化 sdk, 可选的设置日志路径和日志级别
 * @param log_path 日志路径，空字符串使用默认
 * @param log_debug 日志是否打开 debug 级别，默认不开
 */
void init(std::string log_path = "", bool log_debug = false);
}  // namespace longbridge

#endif  // LONGBRIDGE_OPENAPI_INCLUDE_ENGINE_H_
