#ifndef TYPES_H_
#define TYPES_H_

#include <array>
#include <cstdint>
#include <expected>
#include <functional>
#include <string_view>
#include <vector>

namespace euler {
namespace types {

enum SolnErrorCode : int {
  kInvalidArgCount = 0,
  kCannotConvertStrToInt,
  kCannotConvertStrToUInt,
  kNumRetCodes,
};

constexpr std::array<const char*, kNumRetCodes> kRetCodeToStr = {
    "invalid argument count",
    "cannot convert string to int",
    "cannot convert string to unsigned int",
};

using SolnId = unsigned long;
using SolnFuncRet = std::expected<int64_t, SolnErrorCode>;
using SolnFuncArgs = std::vector<std::string_view>;
using SolnFunc = std::function<SolnFuncRet(const SolnFuncArgs&)>;

}  // namespace types
}  // namespace euler

#endif
