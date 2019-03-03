#ifndef DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_PRIM_MST_HPP
#define DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_PRIM_MST_HPP

#include "Graph.hpp"
#include <tuple>

template<typename T>
void print_queue(T q)
{
    std::cout << "Priority Queue: ";
    while (!q.empty())
    {
        std::cout << "(" << std::get<0>(q.top()) << ", " << std::get<1>(q.top()) << ") ";
        q.pop();
    }
    std::cout << '\n';
}

void PrimMST(Graph<Undirected | Adjacent | Weighted> &graph);

#endif //DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_PRIM_MST_HPP