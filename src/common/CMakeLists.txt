cmake_minimum_required(VERSION 3.28)

project(
  common
  DESCRIPTION "Common Types and Conversions"
  LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE conversions.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PE_INCLUDE_DIR})
