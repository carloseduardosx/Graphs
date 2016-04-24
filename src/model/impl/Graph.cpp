#include "../Graph.h"

vector<Vertex *> Graph::getVertexes() {

    return this->vertexes;
}

void Graph::addVertex(Vertex *vertex) {

    this->vertexes.insert(this->iterator, vertex);
}