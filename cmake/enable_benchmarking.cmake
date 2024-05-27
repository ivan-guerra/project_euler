cmake_minimum_required(VERSION 3.28)

include(FetchContent)
FetchContent_Declare(
  googlebenchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.8.4)
FetchContent_MakeAvailable(googlebenchmark)
