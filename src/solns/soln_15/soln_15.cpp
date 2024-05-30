#include "solns/soln_15.h"

#include <cstdint>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

using Matrix = std::vector<std::vector<int64_t>>;

types::SolnFuncRet Soln15(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kDim = euler::conv::StrToULong(args[0]);
  if (!kDim.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  auto IsInBounds = [](int i, int j, int dim) -> bool {
    return (i >= 0) && (i < dim) && (j >= 0) && (j < dim);
  };

  int dim = kDim.value();
  Matrix mat(dim, std::vector<int64_t>(dim, 0));
  for (int i = 0; i < dim; ++i) {
    for (int j = 0; j < dim; ++j) {
      int64_t total = 0;
      if (IsInBounds(i - 1, j, dim)) {
        total += 1 + mat[i - 1][j];
      }
      if (IsInBounds(i, j - 1, dim)) {
        total += 1 + mat[i][j - 1];
      }
      mat[i][j] = total;
    }
  }
  return (mat[dim - 1][dim - 1] + 2);
}

}  // namespace euler
