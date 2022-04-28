//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/6.
//

#include "lib.rs.h"
#include "logger.h"

namespace longbridge {
void init(std::string log_path, bool log_debug) {
  longbridge::init_sdk();
  try {
    logger::init_logger(log_path, log_debug);
  } catch (std::exception &e) {
    printf("init logger err %s\n", e.what());
  }
}
}  // namespace longbridge