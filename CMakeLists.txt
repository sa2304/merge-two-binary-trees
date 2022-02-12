cmake_minimum_required(VERSION 3.20)
project(merge_two_binary_trees)

set(CMAKE_CXX_STANDARD 17)

add_executable(merge_two_binary_trees main.cpp)
add_subdirectory(binary-tree-playground)
target_link_libraries(merge_two_binary_trees binary_tree)
