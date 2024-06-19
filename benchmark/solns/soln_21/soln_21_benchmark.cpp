#include <benchmark/benchmark.h>

#include "solns/soln_21.h"

static void BM_Soln21(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln21({"10000"});
  }
}
BENCHMARK(BM_Soln21);
