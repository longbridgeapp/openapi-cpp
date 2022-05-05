//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/21.
//

/**
 * @file websocket.h
 * @brief WebSocket class
 */

#ifndef LONGBRIDGE_OPENSDK_INCLUDE_WEBSOCKET_H_
#define LONGBRIDGE_OPENSDK_INCLUDE_WEBSOCKET_H_

#include "ws.rs.h"

/**
 * @note WebSocket open cost is a little high.
 * Meanwhile it is need remain until program terminate to handle the push
 * message callback.
 */
namespace websocket {
class Client {
 public:
  Client() = delete;
  /**
   * @param url ws url
   * @param auth user auth
   * @param ty websocket type
   * @param base_url http's url, user can change
   * @note WebSocket type must corresponding to the url, and ty decide ws
   * used callback function, as WsType::QuoteWs related to
   * callback::register_quote_message_handle and WsType::NotificationWs related
   * to callback::register_notification_message_handle
   */
  Client(std::string url, longbridge::Auth auth, ws::WsType ty,
         std::string base_url = "https://openapi.lbkrs.com");

  /**
   * @brief  Websocket send request
   * @param command Command , Please refer to  proto/*.proto
   * or https://openapi.longbridge.sg
   * @param serialized_req serialized pb message
   * @return serialized pb message (response)
   * @note must be called in try block, if error happened, SDK will throw
   * exception
   */
  std::string send_request(int command, std::string serialized_req);

  /**
   * @brief get WebSocketClient current state, as whatever reason, the WebSocket
   * closed, SDK will reconnect forever, and change the state to Reconnecting,
   * if reconnect successfully, the state will change Open.
   * @return the current state
   */
  callback::OpenWsState get_state();

 private:
  rust::Box<ws::OpenWs> _ws;
};

}  // namespace websocket

#endif  // LONGBRIDGE_OPENSDK_INCLUDE_WEBSOCKET_H_
