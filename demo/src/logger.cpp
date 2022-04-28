//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/11.
//

#include "logger.h"
#include <thread>
#include <chrono>

int main() {
    // enable longbridge engine log
    logger::init_logger();


    // can log to file, but the line and function is error
    LOG_ERR("hello longbridge");

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1000ms);
}
