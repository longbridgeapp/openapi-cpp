//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/13.
//

/**
 * @mainpage opensdk-cpp
 * @author wenda.jiang@longbridge.sg
 *
 * This is Longbridge OpenSDK C++ Project.
 *
 * You can use this SDK request Longbridge Server API by Http Or Websocket.
 */

/**
 * @file lib.h
 * @brief SDK 的初始化
 */

#ifndef LONGBRIDGE_OPENSDK_INCLUDE_ENGINE_H_
#define LONGBRIDGE_OPENSDK_INCLUDE_ENGINE_H_
#include "lib.rs.h"
namespace longbridge {
/**
 * @brief init SDK, optional log path and log level
 * @param log_path empty string to use default log path
 * @param log_debug default debug is false, level is warn
 */
void init(std::string log_path = "", bool log_debug = false);
}  // namespace longbridge

#endif  // LONGBRIDGE_OPENSDK_INCLUDE_ENGINE_H_
