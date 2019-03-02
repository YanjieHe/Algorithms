#include "Test_Kruskal_MST.hpp"
#include "../Kruskal_MST.hpp"

void Test_Kruskal_MST::Test()
{
    Test1();
}

void Test_Kruskal_MST::Test1()
{
    int V = 4;
    int E = 5;
    Graph<Undirected | Weighted> graph(V, E);
    graph.AddEdge({0, 1, 10});
    graph.AddEdge({0, 2, 6});
    graph.AddEdge({0, 3, 5});
    graph.AddEdge({1, 3, 15});
    graph.AddEdge({2, 3, 4});
    KruskalMST(graph);
}
