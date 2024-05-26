#ifndef TYPES_H_
#define TYPES_H_

#include <array>
#include <functional>
#include <string_view>
#include <vector>

namespace euler {
namespace types {

enum SolnRetCode : int {
  kSuccess = 0,
  kInvalidArgCount,
  kCannotConvertStrToInt,
  kCannotConvertStrToUInt,
  kNumRetCodes,
};

constexpr std::array<const char*, kNumRetCodes> kRetCodeToStr = {
    "success",
    "invalid argument count",
    "cannot convert string to int",
    "cannot convert string to unsigned int",
};

using SolnId = unsigned long; /**< Project Euler problem ID. */
using SolnFuncArgs =
    std::vector<std::string_view>; /**< Solution function arguments. */
using SolnFunc = std::function<SolnRetCode(
    const SolnFuncArgs&)>; /**< Solution function object. */

}  // namespace types
}  // namespace euler

#endif
