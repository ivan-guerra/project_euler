#include "solns/soln_2.h"

#include <cstdint>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

types::SolnFuncRet Soln2(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kLimit = euler::conv::StrToULong(args[0]);
  if (!kLimit.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  int64_t accumulator = 0;
  unsigned long fib_p1 = 0;
  unsigned long fib_p2 = 1;
  unsigned long tmp = 0;
  while (fib_p2 < kLimit.value()) {
    if (0 == fib_p2 % 2) {
      accumulator += fib_p2;
    }
    tmp = fib_p1;
    fib_p1 = fib_p2;
    fib_p2 += tmp;
  }

  return accumulator;
}

}  // namespace euler
