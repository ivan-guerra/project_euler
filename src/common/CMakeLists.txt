cmake_minimum_required(VERSION 3.28)

project(
  common
  DESCRIPTION "Common Types and Definitions"
  LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE ${PE_INCLUDE_DIR})
