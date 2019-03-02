#include "Kruskal_MST.hpp"
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

bool IsCycle(Graph<Undirected | Weighted> &graph)
{
    int V = graph.V();
    int E = graph.E();
    std::vector<Subset> subsets(V);
    for (int v = 0; v < V; v++)
    {
        subsets.at(v).parent = v;
        subsets.at(v).rank = 0;
    }
    for (int e = 0; e < E; ++e)
    {
        int x = Find(subsets, graph.Edges().at(e).src);
        int y = Find(subsets, graph.Edges().at(e).dest);

        if (x == y)
        {
            return true;
        }
        else
        {
            Union(subsets, x, y);
        }
    }
    return false;
}

void KruskalMST(Graph<Undirected | Weighted> &graph)
{
    std::vector<Edge<Undirected | Weighted>> result(graph.E());
    auto edges{graph.Edges()};
    std::sort(edges.begin(), edges.end(), [](auto x, auto y)
    {
        return x.weight < y.weight;
    });
    std::vector<Subset> subsets(graph.V());
    for (int v = 0; v < graph.V(); v++)
    {
        subsets.at(v).parent = v;
        subsets.at(v).rank = 0;
    }
    int index = 0;
    int e = 0;
    while (e < graph.V() - 1)
    {
        Edge<Undirected | Weighted> nextEdge{edges.at(index)};
        index = index + 1;
        int x = Find(subsets, nextEdge.src);
        int y = Find(subsets, nextEdge.dest);

        if (x != y)
        {
            result.at(e) = nextEdge;
            e++;
            Union(subsets, x, y);
        }
    }
    cout << "Following are the edges in the constructed MST" << endl;
    for (int i = 0; i < e; i++)
    {
        cout << result.at(i).src << " -- " << result.at(i).dest << " == " << result.at(i).weight << endl;
    }
}
