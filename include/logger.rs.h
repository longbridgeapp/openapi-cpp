#pragma once
#include <string>

namespace logger {
void init_logger(const ::std::string &path, bool debug);

void log_error_internal(const ::std::string &s) noexcept;

void log_warn_internal(const ::std::string &s) noexcept;

void log_debug_internal(const ::std::string &s) noexcept;
} // namespace logger
