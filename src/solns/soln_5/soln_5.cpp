#include "solns/soln_5.h"

#include <algorithm>
#include <cstdint>
#include <numeric>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

types::SolnFuncRet Soln5(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kLimit = euler::conv::StrToULong(args[0]);
  if (!kLimit.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  std::vector<int64_t> divisors(kLimit.value());
  std::iota(divisors.begin(), divisors.end(), 1);
  for (int64_t i = kLimit.value();; ++i) {
    if (std::all_of(divisors.cbegin(), divisors.cend(),
                    [&i](int64_t n) { return (0 == i % n); })) {
      return i;
    }
  }
  return -1;
}

}  // namespace euler
