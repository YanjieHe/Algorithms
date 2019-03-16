cmake_minimum_required(VERSION 3.13)
project(Design_and_Analaysis_of_Algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Design_and_Analaysis_of_Algorithms
        main.cpp
        Kruskal_MST.cpp
        Kruskal_MST.hpp
        Disjoint_Set.cpp
        Disjoint_Set.hpp
        test/Test_Disjoint_Set.cpp
        test/Test_Disjoint_Set.hpp
        Union-Find.cpp
        Union-Find.hpp
        test/Test_Union_Find.cpp
        test/Test_Union_Find.hpp Graph.hpp test/Test_Kruskal_MST.cpp test/Test_Kruskal_MST.hpp Prim_MST.cpp Prim_MST.hpp Dijkstra.cpp Dijkstra.hpp test/Test_Prim_MST.cpp test/Test_Prim_MST.hpp test/Test_Dijkstra.cpp test/Test_Dijkstra.hpp Huffman_Coding.cpp Huffman_Coding.hpp Fibonacci.cpp Fibonacci.hpp Bitmasking.cpp Bitmasking.hpp "Wildcard Pattern Matching.cpp" "Wildcard Pattern Matching.hpp")