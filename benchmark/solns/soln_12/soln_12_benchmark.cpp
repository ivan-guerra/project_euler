#include <benchmark/benchmark.h>

#include "solns/soln_12.h"

static void BM_Soln12(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln12({"500"});
  }
}
BENCHMARK(BM_Soln12);
