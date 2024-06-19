#include <benchmark/benchmark.h>

#include "solns/soln_22.h"

static void BM_Soln22(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln22({"../../../inputs/p_22.txt"});
  }
}
BENCHMARK(BM_Soln22);
