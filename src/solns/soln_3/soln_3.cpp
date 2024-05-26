#include "solns/soln_3.h"

#include <algorithm>
#include <cmath>
#include <cstdint>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

bool IsPrime(int64_t n) {
  if (n <= 1) {
    return false;
  }

  for (int i = 2; i <= std::sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

types::SolnFuncRet Soln3(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kLimit = euler::conv::StrToULong(args[0]);
  if (!kLimit.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  int64_t max_prime_factor = 0;
  for (int64_t i = 2; i <= std::sqrt(kLimit.value()); ++i) {
    if (kLimit.value() % i == 0 && IsPrime(i)) {
      max_prime_factor = std::max(max_prime_factor, i);
    }
  }

  return max_prime_factor;
}

}  // namespace euler
