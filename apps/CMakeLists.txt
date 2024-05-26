cmake_minimum_required(VERSION 3.28)

project(
  euler
  DESCRIPTION "Project Euler Solution Driver"
  LANGUAGES CXX)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE euler.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PE_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE common soln_factory)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})
