#include "../Graph.h"

vector<Vertex *> Graph::getVertexes() {

    return this->vertexes;
}

void Graph::addVertex(Vertex *vertex) {

    this->vertexes.push_back(vertex);
}

void Graph::createVertex(int value) {

    Vertex *vertex = new Vertex();
    vertex->setValue(value);

    addVertex(vertex);
}

void Graph::createCorner(int firstValue, int secondValue) {

    Vertex *firstVertex = searchVertex(firstValue);
    Vertex *secondVertex = searchVertex(secondValue);

    if (firstVertex == nullptr || secondVertex == nullptr) {
        cout << "One or both vertexes not found, the corner cannot be created!" << endl;
        return;
    }

    Adjacency *adjacency = new Adjacency();
    adjacency->setNext(secondVertex);

    firstVertex->addAdjacency(adjacency);

    adjacency = new Adjacency();
    adjacency->setNext(firstVertex);

    secondVertex->addAdjacency(adjacency);
}

void Graph::showVertexes() {

    vector<Vertex *> vertexes = getVertexes();

    for (vector<Vertex *>::iterator it = vertexes.begin(); it != vertexes.end(); it++) {

        Vertex *vertex = *it;
        cout << vertex->getValue() << endl;
    }
}

Vertex *Graph::searchVertex(int value) {

    vector<Vertex *> vertexes = getVertexes();

    for (vector<Vertex *>::iterator it = vertexes.begin(); it != vertexes.end(); it++) {

        Vertex *vertex = *it;

        if (vertex->getValue() == value) {
            return vertex;
        }
    }

    return nullptr;
}
