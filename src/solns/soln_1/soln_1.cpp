#include "solns/soln_1.h"

#include <cstdint>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

types::SolnFuncRet Soln1(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  auto limit = euler::conv::StrToULong(args[0]);
  if (!limit.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  int64_t accumulator = 0;
  for (unsigned long i = 0; i < limit.value(); ++i) {
    if ((0 == i % 3) || (0 == i % 5)) {
      accumulator += i;
    }
  }
  return accumulator;
}

}  // namespace euler
