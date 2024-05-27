#include "solns/soln_12.h"

#include <cmath>
#include <cstdint>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

static unsigned long CountDivisors(int64_t n) {
  unsigned long num_divisors = 0;
  for (int64_t i = 1; i <= std::sqrt(n); ++i) {
    if (n % i == 0) {
      num_divisors += 2;
    }
  }
  return num_divisors;
}

types::SolnFuncRet Soln12(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kTargetDivisorCount = euler::conv::StrToULong(args[0]);
  if (!kTargetDivisorCount.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  int i = 2;
  int64_t triangle_num = 1;
  while (CountDivisors(triangle_num) <= kTargetDivisorCount.value()) {
    triangle_num += i;
    i++;
  }

  return triangle_num;
}

}  // namespace euler
