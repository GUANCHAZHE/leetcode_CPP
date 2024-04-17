cmake_minimum_required(VERSION 3.28)
project(leetcode_CPP)

set(CMAKE_CXX_STANDARD 11)

add_executable(leetcode_CPP main.cpp
        tree.cpp
        tree.h
        Solution.cpp
        Solution.h
        ListNode.cpp
        ListNode.h
        GraphAdjMat.cpp
        GraphAdjMat.h)
