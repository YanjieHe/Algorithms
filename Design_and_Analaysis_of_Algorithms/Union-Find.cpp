#include "Union-Find.hpp"

int Find(std::vector<Subset> &subsets, int i)
{
    if (subsets.at(i).parent != i)
    {
        subsets.at(i).parent = Find(subsets, subsets.at(i).parent);
        return subsets.at(i).parent;
    }
    else
    {
        return subsets.at(i).parent;
    }
}

void Union(std::vector<Subset> &subsets, int x, int y)
{
    int xRoot = Find(subsets, x);
    int yRoot = Find(subsets, y);

    if (subsets.at(xRoot).rank < subsets.at(yRoot).rank)
    {
        subsets.at(xRoot).parent = yRoot;
    }
    else if (subsets.at(xRoot).rank > subsets.at(yRoot).rank)
    {
        subsets.at(yRoot).parent = xRoot;
    }
    else
    {
        subsets.at(yRoot).parent = xRoot;
        subsets.at(xRoot).rank++;
    }
}

bool UnionFindIsCycle(Graph &graph)
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