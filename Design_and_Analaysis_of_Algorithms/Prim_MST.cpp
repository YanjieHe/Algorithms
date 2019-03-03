#include "Prim_MST.hpp"
#include <queue>
#include <vector>
#include <limits>
#include <iostream>
#include <tuple>

using std::cout;
using std::endl;

void PrintVector(const std::vector<int> &vec)
{
    cout << "parent: ";
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec.at(i) != -1)
        {
            cout << " (" << vec.at(i) << " -> " << i << ") ";
        }
    }
    cout << endl;
}

void PrimMST(Graph<Undirected | Adjacent | Weighted> &graph)
{
    std::vector<Edge<Undirected | Weighted>> edgeTo(graph.V());
    std::vector<double> distTo(graph.V(), std::numeric_limits<double>::infinity());
    std::vector<bool> marked(graph.V());
    auto comparator = [](const std::tuple<int, double> &x, const std::tuple<int, double> &y)
    {
        return std::get<1>(x) > std::get<1>(y);
    };
    std::priority_queue<
            std::tuple<int, double>,
            std::vector<std::tuple<int, double>>,
            decltype(comparator)>
            pq(comparator);
    distTo.at(0) = 0.0;
    pq.push({0, 0.0});
    while (!pq.empty())
    {
        int src = std::get<0>(pq.top());
        pq.pop();
        marked.at(src) = true;
        for (auto edge: graph.AdjacencyList().at(src))
        {
            int dest = edge.dest;
            if (!marked.at(dest))
            {
                if (edge.weight < distTo.at(dest))
                {
                    edgeTo.at(dest) = edge;
                    distTo.at(dest) = edge.weight;
                    pq.push({dest, edge.weight});
                }
            }
        }
    }
    double sum = 0.0;
    for (int i = 1; i < edgeTo.size(); i++)
    {
        auto edge = edgeTo.at(i);
        cout << edge.src << " -> " << edge.dest << endl;
        sum = sum + edge.weight;
    }
    cout << "sum of weights = " << sum << endl;
}
