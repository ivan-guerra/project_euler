#include "solns/soln_20.h"

#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

#include "common/conversions.h"
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

types::SolnFuncRet Soln20(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  auto n = euler::conv::StrToULong(args[0]);
  if (!n) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  BigNum result;
  std::for_each(args[0].cbegin(), args[0].cend(),
                [&result](char digit) { result.push_back(digit - '0'); });

  int i = *n - 1;
  while (i) {
    result = Multiply(result, i);
    i--;
  }

  return std::accumulate(result.cbegin(), result.cend(), 0ULL, std::plus<>());

  return 0;
}

}  // namespace euler
