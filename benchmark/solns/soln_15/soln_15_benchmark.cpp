#include <benchmark/benchmark.h>

#include "solns/soln_15.h"

static void BM_Soln15(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln15({"20"});
  }
}
BENCHMARK(BM_Soln15);
