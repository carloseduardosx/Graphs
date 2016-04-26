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

    addAdjacency(internalCreateAdjacency(next));
}

void Vertex::createCycleAdjacency(Vertex *next) {

    Adjacency *adjacency = internalCreateAdjacency(next);
    adjacency->getCorner()->setCycle(true);
    addAdjacency(adjacency);
}

Adjacency *Vertex::internalCreateAdjacency(Vertex* next) {

    Corner *corner = new Corner();
    Adjacency *adjacency = new Adjacency();

    corner->setDivergent(next);
    corner->setConvergent(next);
    adjacency->setCorner(corner);

    return adjacency;
}

void Vertex::createConvergentAdjacency(Vertex *toVertex) {

    Corner *corner = new Corner();
    Adjacency *adjacency = new Adjacency();

    corner->setDivergent(nullptr);
    corner->setConvergent(toVertex);
    adjacency->setCorner(corner);
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

        cout << " -> " << adjacency->getCorner()->getConvergent()->getValue();
    }

    cout << endl;
}

void Vertex::showGeneratorTree() {

    cout << "Vector: " << this->value << " => Adjacencies:";
    vector<Adjacency *> adjacencies = getAdjacencies();

    for (vector<Adjacency *>::iterator it = adjacencies.begin(); it != adjacencies.end(); it++) {

        Adjacency *adjacency = *it;
        Vertex *next = adjacency->getCorner()->getConvergent();

        cout << " -> " << next->getValue();

        if (next->getVisited()) {
            cout << "V";
        }
    }
    cout << endl;
}

bool Vertex::getVisited() {
    return this->visited;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}
