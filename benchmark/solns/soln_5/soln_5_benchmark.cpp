#include <benchmark/benchmark.h>

#include "solns/soln_5.h"

static void BM_Soln5(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln5({"20"});
  }
}
BENCHMARK(BM_Soln5);
