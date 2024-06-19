#include "solns/soln_21.h"

#include <numeric>
#include <unordered_map>
#include <unordered_set>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

using DivisorSumCache = std::unordered_map<int, int>;
using AmicableSet = std::unordered_set<int>;

void AddDivisors(int n, DivisorSumCache& cache) {
  if (1 == n) {
    cache[n] = 1;
  }

  for (int i = 1; i < n; ++i) {
    if ((n % i) == 0) {
      cache[n] += i;
    }
  }
}

AmicableSet FindAmicablePairs(const DivisorSumCache& cache) {
  AmicableSet amicable;
  for (const auto& [n, d_n] : cache) {
    if (cache.contains(d_n) && (cache.at(d_n) == n) && (n != d_n)) {
      amicable.insert(n);
      amicable.insert(d_n);
    }
  }
  return amicable;
}

types::SolnFuncRet Soln21(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kLimit = euler::conv::StrToULong(args[0]);
  if (!kLimit.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  DivisorSumCache cache;
  for (unsigned i = 0; i < *kLimit; ++i) {
    AddDivisors(i, cache);
  }

  AmicableSet amicable = FindAmicablePairs(cache);
  return std::accumulate(amicable.cbegin(), amicable.cend(), 0ULL,
                         std::plus<>());
}

}  // namespace euler
