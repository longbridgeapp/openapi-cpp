//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/21.
//

#include "websocket.h"

#include "logger.h"

// anonymity namespace, only visible in this file
namespace {
rust::Box<ws::OpenWs> open_ws(std::string url, longbridge::Auth auth,
                              ws::WsType ty, std::string base_url) {
  return ws::new_open_ws(url, auth, ty, base_url);
}

}  // namespace

namespace websocket {

Client::Client(std::string url, longbridge::Auth auth, ws::WsType ty,
               std::string base_url)
    : _ws(open_ws(url, auth, ty, base_url)) {}

std::string Client::send_request(int command, std::string serialized_req) {
  rust::Vec<uint8_t> req_body;
  for (auto c : serialized_req) {
    req_body.push_back(c);
  }
  ::rust::Vec<::std::uint8_t> resp = _ws->request(command, req_body);
  std::string res;
  for (auto c : resp) {
    res.push_back(c);
  }
  return res;
}

callback::OpenWsState Client::get_state() { return _ws->get_state(); }

}  // namespace websocket
