#include "Test_Union_Find.hpp"
#include "../Union-Find.hpp"
#include <iostream>

namespace Test_Union_Find
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
        cout << boolalpha << UnionFindIsCycle(graph) << endl;
    }
}