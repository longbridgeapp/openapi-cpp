//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/13.
//
#include "http.h"

#include <chrono>
#include <iostream>

#include "const_value.h"
#include "logger.h"
using namespace std::chrono;
using namespace std;

/**
 * As HttpClient new cost is a little high,
 * so we recommend use SingleTon Pattern wrap
 * HttpClient, and you can use one HttpClient
 * send request repeatedly.
 *
 * Usually only if you have multi account(every account has a token),
 * multi HttpClient needed.
 */
class SingleTon {
 public:
  static http::Client& get_http_client() {
    try {
      static http::Client http_client{kBaseUrl, kLanguage, kAuth};
      return http_client;
    } catch (std::exception& e) {
      LOG_ERR("create http_client failed", e.what());
    }
  }

 private:
  SingleTon();
  ~SingleTon();
};

int main() {
  longbridge::init("", true);
  http_internal::CxxRequestOption test{.timeout = 15};
  http::Client& http_client = SingleTon::get_http_client();
  try {
    http_internal::CxxResponse response =
        http_client.get("/v1/trade/asset/account", nlohmann::json{});
    std::string j{response.data};
    for (auto header : response.headers) {
      cout << header.key.c_str() << ": " << header.value.c_str() << std::endl;
    }
    std::cout << j << std::endl;
    nlohmann::json j2 = nlohmann::json::parse(response.data);

    std::cout << j2.dump(4) << std::endl;
  } catch (std::exception& e) {
    printf("http request error %s", e.what());
  }

  return 0;
}
