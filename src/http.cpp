//
// Created by <wenda.jiang@longbridge.sg>  on 2022/4/12.
//
#include "http.h"

#include "logger.h"

namespace {
std::string from_language(http::Language language) {
  switch (language) {
    case http::Language::En: {
      return std::string("en");
    }
    case http::Language::Zh: {
      return std::string("zh-CN");
    }
    case http::Language::Hk: {
      return std::string("zh-HK");
    }
    default: {
      return std::string{"en"};
    }
  }
}

rust::Vec<http_internal::CxxHeader> from_vec_header(
    std::vector<http_internal::CxxHeader>& vec) {
  rust::Vec<http_internal::CxxHeader> res;
  for (auto header : vec) {
    res.push_back(header);
  }
  return res;
}

rust::Box<http_internal::HttpClient> init_http(std::string base_url,
                                               http::Language language,
                                               longbridge::Auth auth) {
  return http_internal::new_http_client(rust::String{base_url},
                                        rust::String{from_language(language)},
                                        rust::String{""}, auth);
}

}  // namespace

namespace http {
Client::~Client() {}

Client::Client(std::string base_url, Language language, longbridge::Auth auth)
    : _client(init_http(base_url, language, auth)) {}

#define CONVERT_URI rust::String internal_uri = rust::String{uri};

#define CONVERT_PAYLOAD \
  rust::String internal_payload = rust::String{payload.dump()};

#define CONVERT_QUERY rust::String internal_query = rust::String{query.dump()};

http_internal::CxxResponse Client::get(
    std::string uri, nlohmann::json query,
    http_internal::CxxRequestOption* options) {
  CONVERT_URI
  CONVERT_QUERY
  return _client->get(internal_uri, internal_query, options);
}

http_internal::CxxResponse Client::post(
    std::string uri, nlohmann::json payload,
    http_internal::CxxRequestOption* options) {
  CONVERT_URI
  CONVERT_PAYLOAD
  return _client->post(internal_uri, internal_payload, options);
}

http_internal::CxxResponse Client::put(
    std::string uri, nlohmann::json payload,
    http_internal::CxxRequestOption* options) {
  CONVERT_URI
  CONVERT_PAYLOAD
  return _client->put(internal_uri, internal_payload, options);
}

http_internal::CxxResponse Client::del(
    std::string uri, nlohmann::json query,
    http_internal::CxxRequestOption* options) {
  CONVERT_URI
  CONVERT_QUERY
  return _client->del(internal_uri, internal_query, options);
}
}  // namespace http
