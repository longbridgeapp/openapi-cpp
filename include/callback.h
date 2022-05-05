/**
 * @file callback.h
 * @brief register callback, call when init SDK
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
 * @brief register the quote push message callback function, must register
 * before Quote WebSocketClient create, otherwise the WebSocket Client creating
 * will fail.
 * @param cb handle quote message push data callback function
 */
void register_quote_message_handle(MsgCallBack cb);

/**
 * @brief register trade data push message callback function, must register
 * before Trade WebSocketClient create, otherwise Trade WebSocketClient creating
 * will fail.
 * @param cb handle trade or notification data callback function
 */
void register_notification_message_handle(MsgCallBack cb);

/**
 * @brief register quote websocket state change callback function, after quote
 * websocket closed(whatever reason) sdk will reconnect forever every 15s, and
 * the websocket client state will be Reconnecting , when reconnect
 * successfully, the state will change Open.
 * @param cb
 */
void register_quote_ws_state_change(StateCallBack cb);

/**
 * @brief register trade websocket state change callback function, note same as
 * forward
 * @param cb
 */
void register_noti_ws_state_change(StateCallBack cb);

}  // extern "C"

}  // namespace callback
