#ifndef CONVERSIONS_H_
#define CONVERSIONS_H_

#include <expected>
#include <string_view>

namespace euler {
namespace conv {

enum class ErrorCode {
  kOutOfRange,
  kInvalidArg,
};

std::expected<long, ErrorCode> StrToLong(const std::string_view str);
std::expected<unsigned long, ErrorCode> StrToULong(const std::string_view str);

}  // namespace conv
}  // namespace euler

#endif
