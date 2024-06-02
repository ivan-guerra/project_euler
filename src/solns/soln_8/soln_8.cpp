#include "solns/soln_8.h"

#include <algorithm>
#include <cstddef>
#include <string_view>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

types::SolnFuncRet Soln8(const types::SolnFuncArgs& args) {
  if (args.size() != 2) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kWindowSize = euler::conv::StrToULong(args[1]);
  if (!kWindowSize.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }
  const std::string_view num = args[0];
  int64_t max_prod = 0;
  for (std::size_t i = 0; (i + kWindowSize.value()) < num.size(); ++i) {
    int64_t prod = 1;
    for (std::size_t j = i; j < (i + kWindowSize.value()); ++j) {
      prod *= (num[j] - '0');
    }
    max_prod = std::max(max_prod, prod);
  }
  return max_prod;
}

}  // namespace euler
