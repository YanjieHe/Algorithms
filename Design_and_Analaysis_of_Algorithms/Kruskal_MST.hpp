#ifndef DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_KRUSKAL_MST_HPP
#define DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_KRUSKAL_MST_HPP

#include "Graph.hpp"
#include "Union-Find.hpp"

bool IsCycle(Graph<Undirected | Weighted> &graph);

void KruskalMST(Graph<Undirected | Weighted> &graph);

#endif //DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_KRUSKAL_MST_HPP
