#ifndef GRAPH_ALGORITHMS_VERTEX_H
#define GRAPH_ALGORITHMS_VERTEX_H

#include <iostream>
#include <vector>
#include "Adjacency.h"
#include "Corner.h"

using namespace std;

class Vertex {

private:

    int value;
    bool visited;
    vector<Adjacency *> adjacencies;

    Adjacency *internalCreateAdjacency(Vertex *vertex);

public:

    int getValue();

    void setValue(int value);

    bool getVisited();

    void setVisited(bool visited);

    vector<Adjacency *> getAdjacencies();

    void addAdjacency(Adjacency *adjacency);

    void createAdjacency(Vertex *next);

    void createCycleAdjacency(Vertex *next);

    void createConvergentAdjacency(Vertex *toVertex);

    void showAdjacencies();

    void showGeneratorTree();
};

#endif