#include <cstddef>
#include <exception>
#include <string>

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

namespace {
template <typename T>
class impl;
} // namespace

#ifndef CXXBRIDGE1_RUST_ERROR
#define CXXBRIDGE1_RUST_ERROR
class Error final : public std::exception {
public:
  Error(const Error &);
  Error(Error &&) noexcept;
  ~Error() noexcept override;

  Error &operator=(const Error &) &;
  Error &operator=(Error &&) &noexcept;

  const char *what() const noexcept override;

private:
  Error() noexcept = default;
  friend impl<Error>;
  const char *msg;
  std::size_t len;
};
#endif // CXXBRIDGE1_RUST_ERROR

namespace {
namespace repr {
struct PtrLen final {
  void *ptr;
  ::std::size_t len;
};
} // namespace repr

template <>
class impl<Error> final {
public:
  static Error error(repr::PtrLen repr) noexcept {
    Error error;
    error.msg = static_cast<const char *>(repr.ptr);
    error.len = repr.len;
    return error;
  }
};
} // namespace
} // namespace cxxbridge1
} // namespace rust

namespace logger {
extern "C" {
::rust::repr::PtrLen logger$cxxbridge1$init_logger(const ::std::string &path, bool debug) noexcept;

void logger$cxxbridge1$log_error_internal(const ::std::string &s) noexcept;

void logger$cxxbridge1$log_warn_internal(const ::std::string &s) noexcept;

void logger$cxxbridge1$log_debug_internal(const ::std::string &s) noexcept;
} // extern "C"

void init_logger(const ::std::string &path, bool debug) {
  ::rust::repr::PtrLen error$ = logger$cxxbridge1$init_logger(path, debug);
  if (error$.ptr) {
    throw ::rust::impl<::rust::Error>::error(error$);
  }
}

void log_error_internal(const ::std::string &s) noexcept {
  logger$cxxbridge1$log_error_internal(s);
}

void log_warn_internal(const ::std::string &s) noexcept {
  logger$cxxbridge1$log_warn_internal(s);
}

void log_debug_internal(const ::std::string &s) noexcept {
  logger$cxxbridge1$log_debug_internal(s);
}
} // namespace logger
