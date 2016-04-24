#ifndef GRAPH_ALGORITHMS_GRAPH_H
#define GRAPH_ALGORITHMS_GRAPH_H

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "Adjacency.h"

using namespace std;

class Graph {

private:

    vector<Vertex*> vertexes;

    Vertex* searchVertex(int value);

public:

    vector<Vertex*> getVertexes();

    void addVertex(Vertex *vertex);

    void createVertex(int value);

    void createCorner(int firstValue, int secondValue);

    void showVertexes();
};

#endif