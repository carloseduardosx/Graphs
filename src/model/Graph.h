#ifndef GRAPH_ALGORITHMS_GRAPH_H
#define GRAPH_ALGORITHMS_GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

class Vertex;
class Graph {

private:

    vector<Vertex*> vertexes;
    vector<Vertex*>::iterator iterator;

public:

    vector<Vertex*> getVertexes();

    void addVertex(Vertex *vertex);

};

#endif