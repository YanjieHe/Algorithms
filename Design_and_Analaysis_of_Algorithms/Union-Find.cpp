#include "Union-Find.hpp"


int Find(std::vector<Subset> &subsets, int i)
{
    if (subsets.at(i).parent != i)
    {
        subsets.at(i).parent = Find(subsets, subsets.at(i).parent);
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

bool IsCycle(Graph &graph)
{

}