cmake_minimum_required(VERSION 3.28)

project(
  soln_factory
  DESCRIPTION "Use the Factory Pattern to Generate a Solution Function"
  LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PE_INCLUDE_DIR})

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC common
  PRIVATE soln_1
          soln_2
          soln_3
          soln_4
          soln_5
          soln_6
          soln_7
          soln_8
          soln_9
          soln_10
          soln_11
          soln_12
          soln_13
          soln_14
          soln_15
          soln_16
          soln_17
          soln_18
          soln_19
          soln_20
          soln_21
          soln_22)
