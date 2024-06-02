#include "solns/soln_11.h"

#include <cstdint>
#include <sstream>
#include <string_view>
#include <utility>
#include <vector>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

using Direction = std::pair<int, int>;
using RowVect = std::vector<int64_t>;
using Matrix = std::vector<RowVect>;

static Matrix LoadMatrix(const std::string_view data, unsigned long dim) {
  Matrix mat(dim, RowVect(dim, 0));
  std::stringstream ss(data.data());
  for (unsigned long i = 0; i < dim; ++i) {
    for (unsigned long j = 0; j < dim; ++j) {
      ss >> mat[i][j];
    }
  }
  return mat;
}

static int64_t GetMaxDirectionalSum(const Matrix& mat, int i, int j,
                                    unsigned long num_vals) {
  const std::vector<Direction> kDirections = {
      {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1},
  };

  const int kDim = mat.size();
  int64_t max_prod = 0;
  for (const Direction& dir : kDirections) {
    int row = i;
    int col = j;
    int64_t prod = 1;
    for (unsigned long k = 0; k < num_vals; ++k) {
      if ((row >= 0) && (row < kDim) && (col >= 0) && (col < kDim)) {
        prod *= mat[row][col];
      } else {
        prod = 0;
        break;
      }
      row += dir.first;
      col += dir.second;
    }
    max_prod = std::max(max_prod, prod);
  }
  return max_prod;
}

types::SolnFuncRet Soln11(const types::SolnFuncArgs& args) {
  if (args.size() != 3) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kDim = euler::conv::StrToULong(args[1]);
  if (!kDim.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  const auto kNumVals = euler::conv::StrToULong(args[2]);
  if (!kNumVals.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  int64_t max_product = 0;
  Matrix mat = LoadMatrix(args[0], kDim.value());
  for (unsigned long i = 0; i < kDim.value(); ++i) {
    for (unsigned long j = 0; j < kDim.value(); ++j) {
      max_product = std::max(max_product,
                             GetMaxDirectionalSum(mat, i, j, kNumVals.value()));
    }
  }
  return max_product;
}

}  // namespace euler
