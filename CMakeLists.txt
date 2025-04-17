cmake_minimum_required(VERSION 3.27)
project(data_struct)

set(CMAKE_CXX_STANDARD 17)

add_executable(data_struct main.cpp
        TreeNode.cpp
        TreeNode.h
        BinaryTree.cpp
        BinaryTree.h
)
