#include "../Vertex.h"

int Vertex::getValue() {

    return this->value;
}

void Vertex::setValue(int value) {

    this->value = value;
}

vector<Adjacency *> Vertex::getAdjacencies() {

    return this->adjacencies;
}

void Vertex::createAdjacency(Vertex *next) {

    Adjacency *adjacency = new Adjacency();
    adjacency->setNext(next);

    addAdjacency(adjacency);
}

void Vertex::addAdjacency(Adjacency *adjacency) {

    this->adjacencies.push_back(adjacency);
}

void Vertex::showAdjacencies() {

    cout << "Vector: " << this->value << " => Adjacencies:";
    vector<Adjacency *> adjacencies = getAdjacencies();

    for (vector<Adjacency *>::iterator it = adjacencies.begin(); it != adjacencies.end(); it++) {

        Adjacency *adjacency = *it;

        cout << " -> " << adjacency->getNext()->getValue();
    }

    cout << endl;
}

bool Vertex::getVisited() {
    return this->visited;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}
