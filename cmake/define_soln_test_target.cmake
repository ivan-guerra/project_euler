# * Macro for defining a solution's unit test target.
function(define_soln_test_target id)
  cmake_minimum_required(VERSION 3.28)

  set(testname soln_${id}_test)

  add_executable(${testname} ${testname}.cpp)

  target_link_libraries(${testname} PRIVATE gtest_main common soln_${id})

  gtest_discover_tests(${testname} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/test)

  set_target_properties(${testname} PROPERTIES FOLDER test)
endfunction()
