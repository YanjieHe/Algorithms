#include "Test_Dijkstra.hpp"
#include "../Dijkstra.hpp"

void Test_Dijkstra::Test()
{
    Test1();
}

void Test_Dijkstra::Test1()
{
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
}
