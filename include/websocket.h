//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/21.
//

/**
 * @file websocket.h
 * @brief WebSocket class
 */

#ifndef LONGBRIDGE_OPENAPI_INCLUDE_WEBSOCKET_H_
#define LONGBRIDGE_OPENAPI_INCLUDE_WEBSOCKET_H_

#include "ws.rs.h"

/**
 * @note websocket 建立 cost
 * 较大，同时需要对象保持生命周期以获得推送数据的回调处理 所以通常需要 websocket
 * 存活到程序的生命周期结束
 */
namespace websocket {
class Client {
 public:
  Client() = delete;
  /**
   * @param url ws url
   * @param auth 用户的授权信息
   * @param ty websocket 类型
   * @param base_url http 的 url， 提供默认参数，可选
   * @note 需要注意 websocket 类型和 url 必须对应，同时 ty 决定了 ws
   * 使用的回调函数 比如 ty = WsType::QuoteWs 对应
   * callback::register_quote_message_handle
   */
  Client(std::string url, longbridge::Auth auth, ws::WsType ty,
         std::string base_url = "https://openapi.lbkrs.com");

  /**
   * @brief 在 Websocket 连接上发起请求
   * @param command 请求对应的 command 数字，含义请参考 proto/*.proto 文件以及
   * 官网 https://openapi.longbridge.sg
   * @param serialized_req 请求的 pb 序列化的字符串
   * @return 响应的字符串，需要自行反序列化为对应的 pb 结构
   * @note 注意本函数需要在 try block
   * 中使用，如果请求失败，会抛出异常，需要用户处理
   */
  std::string send_request(int command, std::string serialized_req);

  /**
   * @brief 获取 websocket client 的当前状态，因为某种原因断连 sdk
   * 会重连，同时更改为 reconneting 状态 如果重连成功会重新更改为 open 状态
   * @return
   */
  callback::OpenWsState get_state();

 private:
  rust::Box<ws::OpenWs> _ws;
};

}  // namespace websocket

#endif  // LONGBRIDGE_OPENAPI_INCLUDE_WEBSOCKET_H_
