#include "../Vertex.h"

int Vertex::getValue() {

    return this->value;
}

void Vertex::setValue(int value) {

    this->value = value;
}

vector<Adjacency*> Vertex::getAdjacencies() {

    return this->adjacencies;
}

void Vertex::addAdjacency(Adjacency *adjacency) {

    this->adjacencies.insert(this->iterator, adjacency);
}