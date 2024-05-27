#include "solns/soln_6.h"

#include <cstdint>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

types::SolnFuncRet Soln6(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kLimit = euler::conv::StrToULong(args[0]);
  if (!kLimit.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  int64_t square_of_sum = kLimit.value() * (kLimit.value() + 1) / 2;
  square_of_sum *= square_of_sum;

  int64_t sum_of_squares = 0;
  for (unsigned long i = 1; i <= kLimit.value(); ++i) {
    sum_of_squares += (i * i);
  }
  return (square_of_sum - sum_of_squares);
}

}  // namespace euler
