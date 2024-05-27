#include <benchmark/benchmark.h>

#include "solns/soln_1.h"

static void BM_Soln1(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln1({"1000"});
  }
}
BENCHMARK(BM_Soln1);
