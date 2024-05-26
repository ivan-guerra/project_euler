#include "solns/soln_1.h"

#include <iostream>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

types::SolnRetCode Soln1(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return types::SolnRetCode::kInvalidArgCount;
  }

  auto limit = euler::conv::StrToULong(args[0]);
  if (!limit.has_value()) {
    return types::SolnRetCode::kCannotConvertStrToUInt;
  }

  unsigned long accumulator = 0;
  for (unsigned long i = 0; i < limit.value(); ++i) {
    if ((0 == i % 3) || (0 == i % 5)) {
      accumulator += i;
    }
  }
  std::cout << accumulator << std::endl;

  return types::SolnRetCode::kSuccess;
}

}  // namespace euler
