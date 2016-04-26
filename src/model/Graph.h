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
        DEPTH, BREADTH, WEIGHT
    };

    vector<Vertex *> getVertexes();

    void addVertex(Vertex *vertex);

    void createVertex(int value);

    void createCorner(int firstValue, int secondValue, int weight);

    void createCycleCorner(int value, int weight);

    void createConvergentCorner(int from, int to, int weight);

    void createDivergentCorner(int from, int to, int weight);

    void showVertexes();

    void search(SearchType searchType);

    string currentGraphType();

    void depthFirstSearch(Vertex *vertex);

    void breadthFirstSearch(Vertex *vertex);

    void updateAllWeight(Vertex *vertex);
};

#endif