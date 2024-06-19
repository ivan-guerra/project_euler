#include <benchmark/benchmark.h>

#include "solns/soln_19.h"

static void BM_Soln19(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln19({"1901-01-01 2000-12-31"});
  }
}
BENCHMARK(BM_Soln19);
