#ifndef GRAPH_ALGORITHMS_VERTEX_H
#define GRAPH_ALGORITHMS_VERTEX_H

#include <iostream>
#include <vector>
#include "Adjacency.h"

using namespace std;

class Vertex {

private:

    int value;
    vector<Adjacency*> adjacencies;

public:

    int getValue();

    void setValue(int value);

    vector<Adjacency*> getAdjacencies();

    void addAdjacency(Adjacency *adjacency);

    void showAdjacencies();
};

#endif