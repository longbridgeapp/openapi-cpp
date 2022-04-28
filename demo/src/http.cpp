//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/13.
//
#include "http.h"

#include <iostream>
#include "const_value.h"
#include "logger.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

/**
 * 推荐的 Client 用法
 * 因为每次创建 Client 的成本比较高
 * 一旦创建可以对同一个 url 的 uri 重复请求
 * 每个 auth 实例对应一个 Client
 * 如果有新的 Auth （多账户） 才需要多个 Client 实例
 */
class SingleTon {
 public:
  static http::Client& get_http_client() {
    try {
      static http::Client http_client{kBaseUrl, kLanguage, kAuth};
      return http_client;
    } catch (std::exception &e) {
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
    nlohmann::json query;
    query["symbol"] = "700.HK";
    query["start_at"] = 1650410999;
    query["end_at"] = 1650510999;
    query["order_id"] = 701276261045858304;
    http_internal::CxxResponse response =
        http_client.get("/v1/test", query);
    std::string j{response.data};
    for (auto header: response.headers) {
      cout << header.key.c_str() << ": " << header.value.c_str() << std::endl;
    }
    std::cout << j << std::endl;
    nlohmann::json j2 = nlohmann::json::parse(response.data);

    std::cout << j2.dump(4) << std::endl;
  } catch (std::exception &e) {
    printf("http request error %s", e.what());
  }

  return 0;
}
