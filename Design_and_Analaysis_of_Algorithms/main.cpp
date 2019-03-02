#include <iostream>
//#include "test/Test_Disjoint_Set.hpp"
#include "test/Test_Union_Find.hpp"
#include "Kruskal_MST.hpp"
#include <cstdint>

int main()
{
//    Test_Disjoint_Set::Test();
    Test_Union_Find::Test();
    int V = 4;
    int E = 5;
    Graph<Undirected | Weighted> graph(V, E);
    graph.AddEdge({0, 1, 10});
    graph.AddEdge({0, 2, 6});
    graph.AddEdge({0, 3, 5});
    graph.AddEdge({1, 3, 15});
    graph.AddEdge({2, 3, 4});
    KruskalMST(graph);
    return 0;
}