#include <benchmark/benchmark.h>

#include "solns/soln_7.h"

static void BM_Soln7(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln7({"10001"});
  }
}
BENCHMARK(BM_Soln7);
