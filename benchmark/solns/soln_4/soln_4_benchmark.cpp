#include <benchmark/benchmark.h>

#include "solns/soln_4.h"

static void BM_Soln4(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln4({""});
  }
}
BENCHMARK(BM_Soln4);
