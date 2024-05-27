# * Macro for defining a solution's benchmark target.
function(define_soln_benchmark_target id)
  cmake_minimum_required(VERSION 3.28)

  set(benchmark_name soln_${id}_benchmark)

  add_executable(${benchmark_name})

  target_sources(${benchmark_name} PRIVATE ${benchmark_name}.cpp)

  target_link_libraries(
    ${benchmark_name} PRIVATE benchmark::benchmark benchmark::benchmark_main
                              soln_${id})

  install(TARGETS ${benchmark_name}
          RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/benchmarks)
endfunction()
