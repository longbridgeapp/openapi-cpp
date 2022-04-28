//
// Created by <wenda.jiang@longbridge.sg> on 2022/4/11.
//

#ifndef LONGBRIDGE_OPENAPI_LOGGER_FORMAT_H
#define LONGBRIDGE_OPENAPI_LOGGER_FORMAT_H

#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "custom_string.h"

namespace logger {
using comm::operator<<;

#define _JUST_GET_66TH_ARG(                                                    \
    _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, \
    _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, \
    _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, \
    _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, \
    _62, _63, _64, N, ...)                                                     \
  N

#define ARG_COUNT(...)                                                         \
  _JUST_GET_66TH_ARG(0, ##__VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, \
                     54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41,   \
                     40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27,   \
                     26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13,   \
                     12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define _NAME(ITEM) #ITEM
#define _NAME_1(_1) _1
#define _NAME_2(_1, _2) _NAME_1(_1) _NAME(_2)
#define _NAME_3(_1, _2, _3) _NAME_2(_1, _2), _NAME(_3)
#define _NAME_4(_1, _2, _3, _4) _NAME_3(_1, _2, _3), _NAME(_4)
#define _NAME_5(_1, _2, _3, _4, _5) _NAME_4(_1, _2, _3, _4), _NAME(_5)
#define _NAME_6(_1, _2, _3, _4, _5, _6) _NAME_5(_1, _2, _3, _4, _5), _NAME(_6)
#define _NAME_7(_1, _2, _3, _4, _5, _6, _7) \
  _NAME_6(_1, _2, _3, _4, _5, _6), _NAME(_7)
#define _NAME_8(_1, _2, _3, _4, _5, _6, _7, _8) \
  _NAME_7(_1, _2, _3, _4, _5, _6, _7), _NAME(_8)
#define _NAME_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) \
  _NAME_8(_1, _2, _3, _4, _5, _6, _7, _8), _NAME(_9)
#define _NAME_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
  _NAME_9(_1, _2, _3, _4, _5, _6, _7, _8, _9), _NAME(_10)
#define _NAME_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
  _NAME_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10), _NAME(_11)
#define _NAME_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
  _NAME_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11), _NAME(_12)
#define _NAME_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
  _NAME_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12), _NAME(_13)
#define _NAME_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
  _NAME_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13), _NAME(_14)
#define _NAME_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, \
                 _15)                                                         \
  _NAME_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14),      \
      _NAME(_15)
#define _NAME_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, \
                 _15, _16)                                                    \
  _NAME_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15), \
      _NAME(_16)

#define _JOIN(x, y) x##y
#define _NAME_N(name, n) _JOIN(name, n)
#define _AGR_NAMES(...) _NAME_N(_NAME_, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define ARG_NAMES(...) _AGR_NAMES({ , ##__VA_ARGS__)}




using ParamNameList = std::vector<const char *>;

inline void _Format(const ParamNameList &name_list, size_t pos,
                    std::ostream &oss) {}

template <typename T, typename... Args>
void _Format(const ParamNameList &name_list, size_t pos, std::ostream &oss,
             const T &head, Args... rest) {
  const char *name = NULL;
  if (pos < name_list.size()) {
    name = name_list[pos];
  }
  if (pos > 0) {
    oss << ", ";
  }
  if (name && name[0] != '"') {
    oss << name << " ";
  }
  oss << head;
  _Format(name_list, pos + 1, oss, rest...);
}

template <typename... Args>
std::string Format(const ParamNameList &name_list, Args... args) {
  std::ostringstream oss;
  _Format(name_list, 0, oss, args...);
  return oss.str();
}

template <typename... Args>
std::string Format(Args... args) {
  std::ostringstream oss;
  ParamNameList name_list;
  _Format(name_list, 0, oss, args...);
  return oss.str();
}

template <typename... Args>
std::string Format(bool with_name, const ParamNameList &name_list,
                   Args... args) {
  if (!with_name) {
    return Format(args...);
  }
  return Format(name_list, args...);
}

namespace CompileTimeCal
{
using size_t = long;

template <char... str>
struct TStaticStr {
  constexpr static const char chars[] = {str..., '\0'};
};
template <char... str>
constexpr const char
    TStaticStr<str...>::chars[];


template <typename strType, uint32_t... indices>
struct TStrMerge {
  typedef TStaticStr<strType{}.chars[indices]...> combine;
};


template <size_t offset, char ch, typename strType, uint32_t... indices>
struct TLastStrInner {
  typedef typename TLastStrInner<offset + 1, strType{}.chars[offset + 1],
                                 strType, indices..., offset>::last last;
};

template <size_t offset, typename strType, uint32_t... indices>
struct TLastStrInner<offset, '\0', strType, indices...> {
  typedef typename TStrMerge<strType, indices...>::combine last;
};

template <size_t start, typename strType>
struct TLastStr {
  typedef
      typename TLastStrInner<start, strType{}.chars[start], strType>::last last;
};

template <typename strType>
struct TLastStr<-1,
                strType>
{
  typedef typename TLastStrInner<0, strType{}.chars[0], strType>::last last;
};

template <size_t offset, char ch, char match, typename strType>
struct TMatchIndexInner {
  constexpr static size_t index =
      ch != match ? TMatchIndexInner<offset - 1, strType{}.chars[offset - 1],
                                     match, strType>::index
                  : offset;
};

template <char ch, char match, typename strType>
struct TMatchIndexInner<0, ch, match, strType> {
  constexpr static size_t index = ch != match ? -1 : 0;
};

template <size_t len, typename strType, char match>
struct TMatchIndex {
  constexpr static size_t index =
      TMatchIndexInner<len - 1, strType{}.chars[len - 1], match,
                       strType>::index;
};

#ifdef _WIN32
template <size_t len, typename strType>
struct TGetFileName {
  typedef typename TLastStr<TMatchIndex<len, strType, '/'>::index + 1,
                            strType>::last name;
};
#else
template <size_t len, typename strType>
struct TGetFileName {
  typedef typename TLastStr<TMatchIndex<len, strType, '\\'>::index + 1,
                            strType>::last name;
};
#endif
};  // namespace CompileTimeCal

}  // namespace logger

#endif  // LONGBRIDGE_OPENAPI_LOGGER_FORMAT_H
