#include <benchmark/benchmark.h>

#include "solns/soln_6.h"

static void BM_Soln6(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln6({"100"});
  }
}
BENCHMARK(BM_Soln6);
