//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/21.
//

#ifndef LONGBRIDGE_OPENAPI_DEMO_SRC_CONST_VALUE_H_
#define LONGBRIDGE_OPENAPI_DEMO_SRC_CONST_VALUE_H_

#include <string>
#include "http.h"
#include "lib.h"

const std::string kBaseUrl = "https://openapi.lbkrs.com";
const http::Language kLanguage = http::Language::Zh;
const longbridge::Auth kAuth{
    .app_key = std::string("your app_key"),
    .app_secret = std::string(
        "your app_secret"),
    .token = std::string{
        "your token"}};

#endif  // LONGBRIDGE_OPENAPI_DEMO_SRC_CONST_VALUE_H_
