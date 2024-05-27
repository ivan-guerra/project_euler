#include <benchmark/benchmark.h>

#include "solns/soln_14.h"

static void BM_Soln14(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln14({"1000000"});
  }
}
BENCHMARK(BM_Soln14);
