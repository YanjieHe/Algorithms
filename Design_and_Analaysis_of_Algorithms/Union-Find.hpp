#ifndef DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_UNION_FIND_HPP
#define DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_UNION_FIND_HPP

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

class Subset
{
public:
    int parent;
    int rank;
};

int Find(std::vector<Subset>& subsets, int i);

void Union(std::vector<Subset>& subsets, int x, int y);

bool UnionFindIsCycle(Graph &graph);

#endif //DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_UNION_FIND_HPP
