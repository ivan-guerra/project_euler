#include "solns/soln_16.h"

#include <algorithm>
#include <functional>
#include <numeric>

#include "common/types.h"

namespace euler {

using BigNum = std::vector<int>;
using BigNumVect = std::vector<BigNum>;

static BigNum Add(const BigNum& a, const BigNum& b) {
  int i = a.size() - 1;
  int j = b.size() - 1;
  int sum = 0;
  int carry = 0;
  BigNum result;
  while (i >= 0 && j >= 0) {
    sum = a[i--] + b[j--] + carry;
    carry = (sum > 9) ? 1 : 0;
    result.push_back(sum % 10);
  }

  while (i >= 0) {
    sum = a[i--] + carry;
    carry = (sum > 9) ? 1 : 0;
    result.push_back(sum % 10);
  }
  while (j >= 0) {
    sum = b[j--] + carry;
    carry = (sum > 9) ? 1 : 0;
    result.push_back(sum % 10);
  }

  if (carry) {
    result.push_back(1);
  }

  std::reverse(result.begin(), result.end());

  return result;
}

static BigNum Multiply(const BigNum& num, int scale) {
  BigNum result(num.size(), 0);
  while (scale--) {
    result = Add(result, num);
  }
  return result;
}

types::SolnFuncRet Soln16(const types::SolnFuncArgs& args) {
  if (!args.empty()) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  BigNum result = {1, 0, 2, 4};
  const int kNumMultiplications = 99;
  for (int i = 0; i < kNumMultiplications; ++i) {
    result = Multiply(result, 1024);
  }
  return std::accumulate(result.cbegin(), result.cend(), 0LL, std::plus<>());
}

}  // namespace euler
