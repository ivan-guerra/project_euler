# * Macro for defining a solution target.
function(define_soln_target id)
  cmake_minimum_required(VERSION 3.28)

  project(
    soln_${id}
    DESCRIPTION "Solution ${id}"
    LANGUAGES CXX)

  add_library(${PROJECT_NAME} STATIC)

  target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}.cpp)

  target_include_directories(${PROJECT_NAME} PUBLIC ${PE_INCLUDE_DIR})

  target_link_libraries(${PROJECT_NAME} PUBLIC common)
endfunction()
