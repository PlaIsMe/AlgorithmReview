cmake_minimum_required(VERSION 3.14)
project(algorithmTesting)

find_package(Python COMPONENTS Interpreter Development)
add_subdirectory("extern/pybind11")

pybind11_add_module(sort_module module.cpp)
pybind11_add_module(search_module module.cpp)
