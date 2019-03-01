#include "Test_Disjoint_Set.hpp"
#include "../Disjoint_Set.hpp"
#include <iostream>

namespace Test_Disjoint_Set
{
    using namespace std;
    void Test()
    {
        Test1();
    }

    void Test1()
    {
        /*
         * 0 ------- 1
         *  \       |
         *   \     |
         *    \   |
         *     \ |
         *      2
         */
        int V = 3;
        int E = 3;
        Graph graph(V, E);
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 2);
        graph.AddEdge(1, 2);
        cout << boolalpha << IsCycle(graph) << endl;
    }
}