#ifndef DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_DISJOINT_SET_HPP
#define DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_DISJOINT_SET_HPP

#include <vector>

class Edge
{
public:
    int src;
    int dest;

    Edge(int src, int dest) : src{src}, dest{dest}
    {

    }
};

class Graph
{
public:
    Graph(int V, int E) : numOfVertices{V}, numOfEdges{E}
    {
        edges.reserve(E);
    }

    int &V()
    {
        return numOfVertices;
    }

    int &E()
    {
        return numOfEdges;
    }

    std::vector<Edge> &Edges()
    {
        return edges;
    }

    void AddEdge(int src, int dest)
    {
        edges.emplace_back(src, dest);
    }

private:
    int numOfVertices;
    int numOfEdges;
    std::vector<Edge> edges;
};

int Find(std::vector<int> &parent, int i);

void Union(std::vector<int> &parent, int x, int y);

bool IsCycle(Graph &graph);

#endif //DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_DISJOINT_SET_HPP
