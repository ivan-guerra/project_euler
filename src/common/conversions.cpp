#include "common/conversions.h"

#include <stdexcept>
#include <string>
#include <string_view>

namespace euler {
namespace conv {

std::expected<long, ErrorCode> StrToLong(const std::string_view& str) {
  try {
    return std::stol(str.data());
  } catch (const std::invalid_argument&) {
    return std::unexpected(ErrorCode::kInvalidArg);
  } catch (const std::out_of_range&) {
    return std::unexpected(ErrorCode::kOutOfRange);
  }
}

std::expected<unsigned long, ErrorCode> StrToULong(
    const std::string_view& str) {
  try {
    return std::stoul(str.data());
  } catch (const std::invalid_argument&) {
    return std::unexpected(ErrorCode::kInvalidArg);
  } catch (const std::out_of_range&) {
    return std::unexpected(ErrorCode::kOutOfRange);
  }
}

}  // namespace conv
}  // namespace euler
