#include "solns/soln_14.h"

#include <algorithm>
#include <cstdint>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

static int64_t CollatzLength(int64_t n) {
  int64_t len = 0;
  while (n != 1) {
    if (n & 1) {
      n = 3 * n + 1;
    } else {
      n >>= 1;
    }
    len++;
  }
  return len;
}

types::SolnFuncRet Soln14(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kLimit = euler::conv::StrToULong(args[0]);
  if (!kLimit.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  int64_t soln = 0;
  int64_t max_len = 0;
  for (unsigned long i = 1; i < kLimit.value(); ++i) {
    int64_t len = CollatzLength(i);
    if (len > max_len) {
      max_len = len;
      soln = i;
    }
  }
  return soln;
}

}  // namespace euler
