cmake_minimum_required(VERSION 3.13)
project(Design_and_Analaysis_of_Algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(Design_and_Analaysis_of_Algorithms main.cpp Kruskal_MST.cpp Kruskal_MST.hpp Disjoint_Set.cpp Disjoint_Set.hpp test/Test_Disjoint_Set.cpp test/Test_Disjoint_Set.hpp Union-Find.cpp Union-Find.hpp)