#include <benchmark/benchmark.h>

#include "solns/soln_13.h"

static void BM_Soln13(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln13({"../../../inputs/p_13.txt", "10"});
  }
}
BENCHMARK(BM_Soln13);
