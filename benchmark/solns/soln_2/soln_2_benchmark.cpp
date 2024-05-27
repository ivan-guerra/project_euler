#include <benchmark/benchmark.h>

#include "solns/soln_2.h"

static void BM_Soln2(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln2({"4000000"});
  }
}
BENCHMARK(BM_Soln2);
