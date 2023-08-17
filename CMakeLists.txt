cmake_minimum_required (VERSION 3.5)

project (henry-cavl)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

set (SOURCES "${source_dir}/main.cpp" "${source_dir}/avl/tree.cpp" "${source_dir}/avl/node.cpp")
set (HEADERS "${source_dir}/avl/tree.hpp" "${source_dir}/avl/node.hpp")

add_executable (henry-cavl ${SOURCES} ${HEADERS})
