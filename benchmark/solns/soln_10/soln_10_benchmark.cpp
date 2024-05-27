#include <benchmark/benchmark.h>

#include "solns/soln_10.h"

static void BM_Soln10(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln10({"2000000"});
  }
}
BENCHMARK(BM_Soln10);
