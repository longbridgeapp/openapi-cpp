/**
 * @file callback.h
 * @brief 注册行情数据以及交易通知的回调函数，在 SDK 初始化时使用
 */

#pragma once

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <new>
#include <ostream>

namespace callback {

enum class OpenWsState {
  Opening,
  Open,
  Reconnecting,
  Closed,
};

using MsgCallBack = void (*)(int32_t, const uint8_t*, uintptr_t);

using StateCallBack = void (*)(OpenWsState);

extern "C" {
/**
 * @brief 注册函数数据回调函数，需要在创建行情 websocket 之前调用，否则行情
 * websocket 创建会失败
 * @param cb 处理行情数据回调的函数
 */
void register_quote_message_handle(MsgCallBack cb);

/**
 * @brief 注册交易资产数据推送回调函数，需要在创建交易资产 websocket
 * 之前调用，否则交易资产 websocket 创建会失败
 * @param cb 处理交易资产数据推送回调的函数
 */
void register_notification_message_handle(MsgCallBack cb);

/**
 * @brief 注册行情 websocket 连接的状态回调，websocket 由于网络等原因断连后 sdk
 * 会一直尝试重连 重连会先变为 reconnecting 状态，重连成功重新会变为 open 状态
 * @param cb
 */
void register_quote_ws_state_change(StateCallBack cb);

/**
 * @brief 注册交易资产 websocket 连接的状态回调，说明同上
 * @param cb
 */
void register_noti_ws_state_change(StateCallBack cb);

}  // extern "C"

}  // namespace callback
