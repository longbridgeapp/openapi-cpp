//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/11.
//

#ifndef LONGBRIDGE_OPENAPI_CUSTOM_STRING_H
#define LONGBRIDGE_OPENAPI_CUSTOM_STRING_H

#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace comm {

#define TO_STRING(obj) ToString(obj).c_str()

#define SHORT_DEBUG_STRING(OBJ) ShortDebugString(TO_STRING(OBJ)).c_str()

inline std::string ParseFromPtr(const uint8_t* body, uintptr_t body_len) {
  std::string res;
  for (auto i = 0; i < body_len; i++) res.push_back(*(body + i));
  return res;
}

inline std::string ShortDebugString(const std::string &sInput,
                                    const uint32_t iMaxLen = 1024) {
  return sInput.size() < iMaxLen ? sInput : sInput.substr(0, iMaxLen) + "...";
}

template <typename T>
std::string ToString(const T &obj) {
  std::stringstream ss;
  ss << obj;
  return ss.str();
}

template <typename out_type, typename in_type>
out_type Convert(const in_type &obj) {
  std::stringstream ss;
  ss << obj;

  out_type result;
  ss >> result;

  return result;
}

#define PRINT(i) \
  std::cout << "Line " << __LINE__ << " : " << #i " = " << (i) << std::endl

// Print a pair
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &object) {
  out << "(" << object.first << ", " << object.second << ")";
  return out;
}

// Print an array
template <
    typename T1, size_t arrSize,
    typename = typename std::enable_if<!std::is_same<T1, char>::value>::type>
std::ostream &operator<<(std::ostream &out, const T1 (&arr)[arrSize]) {
  const char *separator = "";

  out << "[";
  for (const auto &element : arr) {
    out << separator;
    out << element;
    separator = ", ";
  }
  out << "]";

  return out;
}
//

// Print a vector
template <typename T1>
std::ostream &operator<<(std::ostream &out, const std::vector<T1> &object) {
  const char *separator = "";

  out << "[";
  for (const auto &element : object) {
    out << separator;
    out << element;
    separator = ", ";
  }
  out << "]";

  return out;
}

// Print a set
template <typename T1>
std::ostream &operator<<(std::ostream &out, const std::set<T1> &object) {
  const char *separator = "";

  out << "{";
  for (const auto &element : object) {
    out << separator;
    out << element;
    separator = ", ";
  }
  out << "}";

  return out;
}

// Print a unordered_set
template <typename T1>
std::ostream &operator<<(std::ostream &out,
                         const std::unordered_set<T1> &object) {
  const char *separator = "";

  out << "{";
  for (const auto &element : object) {
    out << separator;
    out << element;
    separator = ", ";
  }
  out << "}";

  return out;
}

// Print a map
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::map<T1, T2> &object) {
  const char *separator = "";

  out << "{";
  for (const auto &element : object) {
    out << separator;
    out << element;
    separator = ", ";
  }
  out << "}";

  return out;
}

// Print an unordered map
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out,
                         const std::unordered_map<T1, T2> &object) {
  const char *separator = "";

  out << "{";
  for (const auto &element : object) {
    out << separator;
    out << element;
    separator = ", ";
  }
  out << "}";

  return out;
}

// Print a stack
template <typename T1>
std::ostream &operator<<(std::ostream &out, const std::stack<T1> &object) {
  std::stack<T1> object_copy(object);
  const char *separator = "";

  out << "[";
  while (!object_copy.empty()) {
    out << separator;
    out << object_copy.top();
    object_copy.pop();
    separator = ", ";
  }
  out << "]";

  return out;
}

// Print a queue
template <typename T1>
std::ostream &operator<<(std::ostream &out, const std::queue<T1> &object) {
  std::queue<T1> object_copy(object);
  const char *separator = "";

  out << "[";
  while (!object_copy.empty()) {
    out << separator;
    out << object_copy.front();
    object_copy.pop();
    separator = ", ";
  }
  out << "]";

  return out;
}

// Print a list
template <typename T1>
std::ostream &operator<<(std::ostream &out, const std::list<T1> &object) {
  const char *separator = "";

  out << "[";
  for (const auto &element : object) {
    out << separator;
    out << element;
    separator = ", ";
  }
  out << "]";

  return out;
}

// Print a tuple
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::tuple<T1, T2> &object) {
  out << "<";
  {
    out << std::get<0>(object);
    out << ", ";
    out << std::get<1>(object);
  }
  out << ">";

  return out;
}

// Print a touple size of 3
template <typename T1, typename T2, typename T3>
std::ostream &operator<<(std::ostream &out,
                         const std::tuple<T1, T2, T3> &object) {
  out << "<";
  {
    out << std::get<0>(object);
    out << ", ";
    out << std::get<1>(object);
    out << ", ";
    out << std::get<2>(object);
  }
  out << ">";

  return out;
}

// Print a touple size of 4
template <typename T1, typename T2, typename T3, typename T4>
std::ostream &operator<<(std::ostream &out,
                         const std::tuple<T1, T2, T3, T4> &object) {
  out << "<";
  {
    out << std::get<0>(object);
    out << ", ";
    out << std::get<1>(object);
    out << ", ";
    out << std::get<2>(object);
    out << ", ";
    out << std::get<3>(object);
  }
  out << ">";

  return out;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
std::ostream &operator<<(std::ostream &out,
                         const std::tuple<T1, T2, T3, T4, T5> &object) {
  out << "<";
  {
    out << std::get<0>(object);
    out << ", ";
    out << std::get<1>(object);
    out << ", ";
    out << std::get<2>(object);
    out << ", ";
    out << std::get<3>(object);
    out << ", ";
    out << std::get<4>(object);
  }
  out << ">";

  return out;
}

}  // namespace comm

#endif  // LONGBRIDGE_OPENAPI_CUSTOM_STRING_H
