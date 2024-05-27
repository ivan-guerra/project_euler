#include <benchmark/benchmark.h>

#include "solns/soln_9.h"

static void BM_Soln9(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln9({"1000"});
  }
}
BENCHMARK(BM_Soln9);
