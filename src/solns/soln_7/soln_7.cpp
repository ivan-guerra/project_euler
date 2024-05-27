#include "solns/soln_7.h"

#include <cmath>
#include <cstdint>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

static bool IsPrime(int64_t n) {
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

types::SolnFuncRet Soln7(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kLimit = euler::conv::StrToULong(args[0]);
  if (!kLimit.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  int64_t limit = kLimit.value();
  int64_t curr_prime = 0;
  int64_t i = 2;
  while (limit) {
    if (IsPrime(i)) {
      curr_prime = i;
      limit--;
    }
    i++;
  }
  return curr_prime;
}

}  // namespace euler
