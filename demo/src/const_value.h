//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/21.
//

#ifndef LONGBRIDGE_OPENSDK_DEMO_SRC_CONST_VALUE_H_
#define LONGBRIDGE_OPENSDK_DEMO_SRC_CONST_VALUE_H_

#include <string>

#include "http.h"
#include "lib.h"

const std::string kBaseUrl = "https://openapi.lbkrs.com";
const http::Language kLanguage = http::Language::Zh;
const longbridge::Auth kAuth{
    .app_key = std::string("3f2575a183e83bb7f0fa8626d8c580eb"),
    .app_secret = std::string(
        "532eb01ba2fe27977c4a845fa0b861d5251a6a9584828d104b97fdeb6dfb7619"),
    .access_token = std::string{
        "eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9."
        "eyJpc3MiOiJsb25nYnJpZGdlIiwic3ViIjoiYWNjZXNzX3Rva2VuIiwiZXhwIjoxNjUyNT"
        "MwNDM3LCJpYXQiOjE2NTExNTUyMjAsImFrIjoiM2YyNTc1YTE4M2U4M2JiN2YwZmE4NjI2"
        "ZDhjNTgwZWIiLCJhYWlkIjoyMDAwMTc5NCwiYWMiOiJsYiIsIm1pZCI6NzIyODg1Mywic2"
        "lkIjoiN0dOYmpVWHB4VE1qNjdGbjVIcURYUT09IiwiYmwiOi0xLCJ1bCI6MCwiaWsiOiJs"
        "Yl8yMDAwMTc5NCJ9.nV6LYuzd3pn_Sstj-q3YZjvMz7YwnzBvysxjEllLbN4sspjaH-"
        "1OoiryYfaDdNzWOPdsx7AjAie9xlfOE8EKbZg9ab571cUVGFzWhevsQjUjU7xKkfdqFjzM"
        "MMulJ56dWGCBTcvU0Bmfy78g-GYsOwmOW8RiNRyoPwVjCVu_"
        "45I5X07mC4zkPurGkxxm83MRHOrhbZfGRIQtNbok_"
        "mFSNRMdAr9E5QNFaK3K6aGIzJh7IFXEu2jIkTMVyBqTPlNONR_"
        "jEMg1twCNXspzhxCFqvtu8OHHdwxMLM3LCW8jxapbB1U1y84On5IMVT58lH4pYSSXJQNx2"
        "Vlb9_"
        "HTJyecA1k3mwJDdCU64HcIwBDF880L8qerGZAfRnkWSzaferqBcWiOOGT7lT8JuyJhlqUJ"
        "otggniqZngY2yXPZKoPM0hGH_eqfXz_FcevBBSF8a4c-a1Ko6otLYnAW6sJVO5Nlh_"
        "2jltN7tV7MG8t0YZwvHDnlfVFsqG1cAgkj9wlTzXULU4hCDomtPZF-"
        "0tgykVUqEJ0vm3vRtpuZq_"
        "Iy3eXuO4TxdCCbzIdS1Oogn7naKMEapd6hixVkcwpUmcLc6d7syktNanN4HZgEEtUtrYhD"
        "31_CESkdk_ROWBNCYjb2lZtUT-72SN45LOAD6DR1O1v163bRsV1Dhj6ngrt95mZsd2Y"}};

#endif  // LONGBRIDGE_OPENSDK_DEMO_SRC_CONST_VALUE_H_
