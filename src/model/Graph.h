#ifndef GRAPH_ALGORITHMS_GRAPH_H
#define GRAPH_ALGORITHMS_GRAPH_H

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "Adjacency.h"

using namespace std;

class Graph {

private:

    vector<Vertex *> vertexes;

    vector<Vertex *> searchVertex(int value);

public:

    enum SearchType {
        DEPTH, BREADTH
    };

    vector<Vertex *> getVertexes();

    void addVertex(Vertex *vertex);

    void createVertex(int value);

    void createCorner(int firstValue, int secondValue);

    void createCycleCorner(int value);

    void createConvergentCorner(int from, int to);

    void createDivergentCorner(int from, int to);

    void showVertexes();

    void search(SearchType searchType);

    void depthFirstSearch(Vertex *vertex);

    void breadthFirstSearch(Vertex *vertex);
};

#endif