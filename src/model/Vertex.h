#ifndef GRAPH_ALGORITHMS_VERTEX_H
#define GRAPH_ALGORITHMS_VERTEX_H

#include <iostream>
#include <vector>

using namespace std;

class Adjacency;
class Vertex {

private:

    int value;
    vector<Adjacency*> adjacencies;
    vector<Adjacency*>::iterator iterator;

public:

    int getValue();

    void setValue(int value);

    vector<Adjacency*> getAdjacencies();

    void addAdjacency(Adjacency *adjacency);
};

#endif