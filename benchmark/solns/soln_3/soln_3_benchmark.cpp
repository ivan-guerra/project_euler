#include <benchmark/benchmark.h>

#include "solns/soln_3.h"

static void BM_Soln3(benchmark::State& state) {
  for (auto _ : state) {
    euler::Soln3({"600851475143"});
  }
}
BENCHMARK(BM_Soln3);
