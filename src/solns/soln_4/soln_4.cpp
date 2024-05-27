#include "solns/soln_4.h"

#include <algorithm>
#include <cstdint>

#include "common/types.h"

namespace euler {

bool IsPalindrome(int64_t n) {
  int64_t rev_n = 0;
  int64_t old_n = n;
  while (n) {
    rev_n = rev_n * 10 + (n % 10);
    n /= 10;
  }
  return (old_n == rev_n);
}

types::SolnFuncRet Soln4(__attribute__((unused))
                         const types::SolnFuncArgs& args) {
  constexpr int64_t kLimit = 999;
  int64_t max_product = 0;
  for (int64_t i = 100; i <= kLimit; ++i) {
    for (int64_t j = 100; j <= kLimit; ++j) {
      int64_t product = i * j;
      if (IsPalindrome(product)) {
        max_product = std::max(max_product, product);
      }
    }
  }
  return max_product;
}

}  // namespace euler
