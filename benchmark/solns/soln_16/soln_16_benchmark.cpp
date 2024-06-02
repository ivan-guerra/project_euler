#include <benchmark/benchmark.h>

#include "solns/soln_16.h"

static void BM_Soln16(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln16({""});
  }
}
BENCHMARK(BM_Soln16);
