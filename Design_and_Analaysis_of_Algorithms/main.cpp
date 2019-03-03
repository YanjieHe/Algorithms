#include <iostream>
#include "test/Test_Disjoint_Set.hpp"
#include "test/Test_Union_Find.hpp"
#include "test/Test_Kruskal_MST.hpp"
#include "test/Test_Prim_MST.hpp"
#include "Dijkstra.hpp"
#include <cstdint>

int main()
{
    Test_Disjoint_Set::Test();
    Test_Union_Find::Test();
    Test_Kruskal_MST::Test();
    Test_Prim_MST::Test();
    int V = 9;
    std::vector<std::vector<double>> graph = {{0, 4,  0, 0,  0,  0,  0, 8,  0},
                                              {4, 0,  8, 0,  0,  0,  0, 11, 0},
                                              {0, 8,  0, 7,  0,  4,  0, 0,  2},
                                              {0, 0,  7, 0,  9,  14, 0, 0,  0},
                                              {0, 0,  0, 9,  0,  10, 0, 0,  0},
                                              {0, 0,  4, 14, 10, 0,  2, 0,  0},
                                              {0, 0,  0, 0,  0,  2,  0, 1,  6},
                                              {8, 11, 0, 0,  0,  0,  1, 0,  7},
                                              {0, 0,  2, 0,  0,  0,  6, 7,  0}
    };
    Dijkstra(graph, V, 0);
    return 0;
}