//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/21.
//

#include "websocket.h"

#include <thread>

#include "callback.h"
#include "const_value.h"
#include "logger.h"
#include "proto/quote.pb.h"

/**
 * ws create cost is a little high, so use singleton pattern
 */

class SingleTon {
 public:
  static websocket::Client& get_ws() {
    static websocket::Client ws{"wss://openapi-quote.longbridge.global", kAuth,
                                ws::WsType::QuoteWs};
    return ws;
  }

 private:
  SingleTon();
  ~SingleTon();

  SingleTon(SingleTon& lhs);
  const SingleTon& operator=(SingleTon& lhs);
};

void on_state(callback::OpenWsState state) {
  if (state == callback::OpenWsState::Open) {
    quote::SubscribeRequest sub_req;
    sub_req.add_symbol("700.HK");
    sub_req.add_sub_type(quote::SubType::TRADE);
    sub_req.add_sub_type(quote::SubType::DEPTH);
    sub_req.add_sub_type(quote::SubType::QUOTE);
    sub_req.set_is_first_push(true);
    LOG_ERR("on open");

    try {
      std::string resp = SingleTon::get_ws().send_request(quote::Command::Subscribe,
                                       sub_req.SerializeAsString());
      quote::SubscriptionResponse de_resp;
      if (de_resp.ParseFromString(resp)) {
        printf("sub resp %s\n", de_resp.DebugString().c_str());
      }

    } catch (std::exception &e) {
      LOG_ERR("send_request err", e.what());
    }
  }
}

void on_message(int32_t command, const uint8_t* body, uintptr_t body_len) {
  std::string msg = comm::ParseFromPtr(body, body_len);
  switch (command) {
    case quote::Command::PushDepthData: {
      quote::PushDepth resp;
      if (resp.ParseFromString(msg)) {
        LOG_ERR(command, resp.DebugString());
        // todo handle msg
      } else {
        LOG_ERR("parse PushDepth error");
      }
      break;
    }
    case quote::Command::PushQuoteData: {
      quote::PushQuote resp;
      if (resp.ParseFromString(msg)) {
        LOG_ERR(command, resp.DebugString());
        // todo handle msg
      } else {
        LOG_ERR("parse PushQuote error");
      }
      break;
    }
    case quote::Command::PushTradeData: {
      quote::PushTrade resp;
      if (resp.ParseFromString(msg)) {
        LOG_ERR(command, resp.DebugString());
        // todo handle msg
      } else {
        LOG_ERR("parse PushTrade error");
      }
      break;
    }
    default: {
      LOG_ERR("not known command", command);
    }
  };
}

int main() {
  longbridge::init();
  callback::register_quote_message_handle(on_message);
  callback::register_quote_ws_state_change(on_state);
  quote::SecurityRequest req;
  req.set_symbol("700.HK");
  websocket::Client& ws = SingleTon::get_ws();

  std::string resp;
  try {
    resp = ws.send_request(10, req.SerializeAsString());
  } catch (std::exception& e) {
    printf("send request err %s", e.what());
    return 0;
  }
  quote::SecurityStaticInfoResponse de_resp;
  if (de_resp.ParseFromString(resp)) {
    for (auto se : de_resp.secu_static_info()) {
      printf("%s\n", se.name_cn().c_str());
    }
    // DebugString use o, so chinese unreadable code
    // https://www.fpstop.com/third/protobuf_string/
    printf("%s\n", de_resp.DebugString().c_str());
  } else {
    printf("deserialize response error\n");
  }

  // 保留 ws 的生命周期可以在日志中看到行情数据的推送
  while (true) {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1000ms);
  }

  return 0;
}
