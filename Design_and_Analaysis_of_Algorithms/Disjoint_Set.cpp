#include "Disjoint_Set.hpp"
#include "Union-Find.hpp"


int Find(std::vector<int> &parent, int i)
{
    if (parent.at(i) == -1)
    {
        return i;
    }
    else
    {
        return Find(parent, parent.at(i));
    }
}

void Union(std::vector<int> &parent, int x, int y)
{
    int xSet = Find(parent, x);
    int ySet = Find(parent, y);
    if (xSet != ySet)
    {
        parent.at(xSet) = ySet;
    }
}

bool IsCycle(Graph &graph)
{
    std::vector<int> parent(graph.V(), -1);
    for (int i = 0; i < graph.E(); i++)
    {
        int x = Find(parent, graph.Edges().at(i).src);
        int y = Find(parent, graph.Edges().at(i).dest);
        if (x == y)
        {
            return true;
        }
        else
        {
            Union(parent, x, y);
        }
    }
    return false;
}