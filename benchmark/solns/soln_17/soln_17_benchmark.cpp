#include <benchmark/benchmark.h>

#include "solns/soln_17.h"

static void BM_Soln17(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln17({"1000"});
  }
}
BENCHMARK(BM_Soln17);
