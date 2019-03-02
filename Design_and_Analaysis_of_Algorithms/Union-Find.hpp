#ifndef DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_UNION_FIND_HPP
#define DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_UNION_FIND_HPP

#include <vector>
#include "Graph.hpp"

class Subset
{
public:
    int parent;
    int rank;
};

int Find(std::vector<Subset> &subsets, int i);

void Union(std::vector<Subset> &subsets, int x, int y);

bool IsCycle(Graph<Undirected> &graph);

#endif //DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_UNION_FIND_HPP
