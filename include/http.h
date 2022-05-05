//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/12.
//

/**
 * @file http.h
 * @brief Client class
 */

#ifndef LONGBRIDGE_OPENSDK_HTTP_H
#define LONGBRIDGE_OPENSDK_HTTP_H
#include <string>
#include <vector>

#include "http.rs.h"
#include "json.hpp"
#include "lib.rs.h"

namespace http {
enum class Language { Zh, Hk, En };
// singleton pattern handle http request
/**
 * @note Client 的 get post put del need be called in try block,
 * when error happened, SDK will throw exception.
 */
class Client {
 public:
  ~Client();
  /**
   * @param base_url request base url
   * @param language language setting
   * @param auth token is optional
   */
  Client(std::string base_url, Language language, longbridge::Auth auth);

  /**
   * @param uri like "/v1/test"
   * @param query get json query, like {"x": "y"} => x=y
   * @param options optional headers, default null
   * @return headers and data(json)
   */
  http_internal::CxxResponse get(
      std::string uri, nlohmann::json query,
      http_internal::CxxRequestOption* options = nullptr);
  /**
   * @param uri post uri
   * @param payload post payload json
   * @param options optional headers, default null
   * @return headers and data(json)
   */
  http_internal::CxxResponse post(
      std::string uri, nlohmann::json payload,
      http_internal::CxxRequestOption* options = nullptr);
  /**
   * @param uri put uri
   * @param payload json put payload
   * @param options optional headers, default null
   * @return headers and data(json)
   */
  http_internal::CxxResponse put(
      std::string uri, nlohmann::json payload,
      http_internal::CxxRequestOption* options = nullptr);
  /**
   * @param uri del uri
   * @param query del json query
   * @param options optional headers, default null
   * @return headers and data(json)
   */
  http_internal::CxxResponse del(
      std::string uri, nlohmann::json query,
      http_internal::CxxRequestOption* options = nullptr);

 private:
  ::rust::Box<http_internal::HttpClient> _client;
};
}  // namespace http

#endif  // LONGBRIDGE_OPENSDK_HTTP_H
