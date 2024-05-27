#include "solns/soln_10.h"

#include <cstdint>
#include <functional>
#include <numeric>
#include <unordered_set>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

static std::unordered_set<unsigned long> SieveOfEratosthenes(unsigned long n) {
  std::unordered_set<unsigned long> primes;
  for (unsigned long i = 2; i < n + 1; ++i) {
    primes.insert(i);
  }

  for (unsigned long p = 2; p * p <= n; p++) {
    if (primes.contains(p)) {
      for (unsigned long i = p * p; i <= n; i += p) {
        primes.erase(i);
      }
    }
  }
  return primes;
}

types::SolnFuncRet Soln10(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kLimit = euler::conv::StrToULong(args[0]);
  if (!kLimit.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  auto primes = SieveOfEratosthenes(kLimit.value());
  int64_t acc = 0;
  return std::accumulate(primes.cbegin(), primes.cend(), acc, std::plus<>());
}

}  // namespace euler
