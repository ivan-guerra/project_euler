cmake_minimum_required(VERSION 3.28)

project(project_euler DESCRIPTION "Project Euler Solutions")

set(PE_INCLUDE_DIR
    "${CMAKE_SOURCE_DIR}/include"
    CACHE STRING "${PROJECT_NAME} include directory.")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(set_compile_link_flags)
add_subdirectory(apps)
add_subdirectory(src)

include(enable_unit_testing)
add_subdirectory(test)
