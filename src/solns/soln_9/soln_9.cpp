#include "solns/soln_9.h"

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

types::SolnFuncRet Soln9(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kTarget = euler::conv::StrToULong(args[0]);
  if (!kTarget.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  for (unsigned long i = 1; i < kTarget.value(); ++i) {
    for (unsigned long j = 1; j < kTarget.value(); ++j) {
      for (unsigned long k = 1; k < kTarget.value(); ++k) {
        if (i + j + k == kTarget.value()) {
          auto i2 = i * i;
          auto j2 = j * j;
          auto k2 = k * k;
          if ((i2 + j2) == k2) {
            return i * j * k;
          }
        }
      }
    }
  }
  return 0;
}

}  // namespace euler
