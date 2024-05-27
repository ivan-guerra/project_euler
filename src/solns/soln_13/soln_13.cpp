#include "solns/soln_13.h"

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <numeric>
#include <string>
#include <string_view>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

using BigNum = std::vector<int>;
using BigNumVect = std::vector<BigNum>;

static BigNumVect LoadNums(const std::string_view& num_file) {
  std::ifstream is(num_file.data());
  std::string line;
  BigNumVect nums;
  while (std::getline(is, line)) {
    BigNum num;
    for (const char& c : line) {
      num.push_back(c - '0');
    }
    nums.push_back(num);
  }
  return nums;
}

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

types::SolnFuncRet Soln13(const types::SolnFuncArgs& args) {
  if (args.size() != 2) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kNumDigits = euler::conv::StrToULong(args[1]);
  if (!kNumDigits.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  BigNumVect nums = LoadNums(args[0]);
  BigNum result = std::accumulate(
      nums.cbegin(), nums.cend(), BigNum(nums[0].size(), 0),
      [](const BigNum& a, const BigNum& b) { return Add(a, b); });

  int64_t ans = 0;
  return std::accumulate(
      result.cbegin(), result.cbegin() + kNumDigits.value(), ans,
      [](int64_t ans, int digit) { return (ans * 10 + digit); });
}

}  // namespace euler
