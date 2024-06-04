#include <benchmark/benchmark.h>

#include "solns/soln_18.h"

static void BM_Soln18(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln18({"../../../inputs/p_18.txt"});
  }
}
BENCHMARK(BM_Soln18);
