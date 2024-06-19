#include <benchmark/benchmark.h>

#include "solns/soln_20.h"

static void BM_Soln20(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln20({"100"});
  }
}
BENCHMARK(BM_Soln20);
