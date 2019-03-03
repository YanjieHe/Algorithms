#include "Dijkstra.hpp"
#include <limits>
#include <iostream>
#include <cmath>

void Dijkstra(const std::vector<std::vector<double>> &graph, int V, int src)
{
    auto minDistance = [V](const std::vector<double> &dist, const std::vector<bool> &sptSet) -> int
    {
        double min = std::numeric_limits<double>::infinity();
        int min_index = -1;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet.at(v) && dist.at(v) <= min)
            {
                min = dist.at(v);
                min_index = v;
            }
        }

        return min_index;
    };
    auto printSolution = [](const std::vector<double> &dist)
    {
        using namespace std;
        cout << "Vertex Distance from Source" << endl;
        for (int i = 0; i < dist.size(); i++)
        {
            cout << i << " -- " << dist.at(i) << endl;
        }
    };
    std::vector<double> dist(V, std::numeric_limits<double>::infinity());
    std::vector<bool> sptSet(V, false); /* short path tree set */
    dist.at(src) = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet.at(u) = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet.at(v) && graph.at(u).at(v) && !std::isinf(dist.at(u)) &&
                dist.at(u) + graph.at(u).at(v) < dist.at(v))
            {
                dist.at(v) = dist.at(u) + graph.at(u).at(v);
            }
        }
    }
    printSolution(dist);
}
