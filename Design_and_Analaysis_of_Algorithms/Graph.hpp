#ifndef DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_GRAPH_HPP
#define DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_GRAPH_HPP

#include <vector>

enum EdgeType
{

    Undirected,
    Directed = 2,
    Adjacent = 4,
    Weighted = 8
};

template<int type>
class Edge
{

};

template<>
class Edge<Undirected>
{
public:
    int src;
    int dest;

    Edge() : src{0}, dest{0}
    {

    }

    Edge(int src, int dest) : src{src}, dest{dest}
    {

    }
};

template<>
class Edge<Undirected | Weighted>
{
public:
    int src;
    int dest;
    double weight;

    Edge() : src{0}, dest{0}, weight{0}
    {

    }

    Edge(int src, int dest, double weight) : src{src}, dest{dest}, weight{weight}
    {

    }
};

template<int type>
class Graph
{

};

template<>
class Graph<Undirected>
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

    std::vector<Edge<EdgeType::Undirected>> &Edges()
    {
        return edges;
    }

    void AddEdge(const Edge<EdgeType::Undirected> &edge)
    {
        edges.push_back(edge);
    }

private:
    int numOfVertices;
    int numOfEdges;
    std::vector<Edge<EdgeType::Undirected>> edges;
};

template<>
class Graph<Undirected | Weighted>
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

    std::vector<Edge<Undirected | Weighted>> &Edges()
    {
        return edges;
    }

    void AddEdge(const Edge<Undirected | Weighted> &edge)
    {
        edges.push_back(edge);
    }

private:
    int numOfVertices;
    int numOfEdges;
    std::vector<Edge<Undirected | Weighted>> edges;
};

template<>
class Graph<Undirected | Adjacent | Weighted>
{
public:
    Graph(int V) : numOfVertices{V}, adj(V)
    {

    }

    void AddEdge(int src, int dest, double weight)
    {
        adj.at(src).emplace_back(src, dest, weight);
        adj.at(dest).emplace_back(dest, src, weight);
    }

    int &V()
    {
        return numOfVertices;
    }

    std::vector<std::vector<Edge<Undirected | Weighted>>> &AdjacencyList()
    {
        return adj;
    }

private:
    std::vector<std::vector<Edge<Undirected | Weighted>>> adj;
    int numOfVertices;
};

#endif //DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_GRAPH_HPP
