# ------------------------------------------------------------------------------
# Copyright (c) 2025, Onur Tuncer, PhD, Istanbul Technical University
#
# SPDX-License-Identifier: BSD-3-Clause
# License-Filename: LICENSE
# ------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)
project(MatplotDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(MATPLOTPP_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(MATPLOTPP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(MATPLOTPP_BUILD_BENCHMARKS OFF CACHE BOOL "" FORCE)
set(MATPLOTPP_BUILD_EXPERIMENTAL_OPENGL_BACKEND OFF CACHE BOOL "" FORCE)
set(MATPLOTPP_USE_BLAS_LAPACK OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    matplotplusplus
    GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus.git
    GIT_TAG v1.2.0
)

FetchContent_MakeAvailable(matplotplusplus)

if (MSVC)
   
    target_compile_options(matplot PRIVATE /WX-)

    target_compile_options(matplot PRIVATE /wd4834)
endif()

add_executable(matplot_demo src/main.cpp)

target_link_libraries(matplot_demo PRIVATE matplot)
