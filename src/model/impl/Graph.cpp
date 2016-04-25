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

    firstVertex->createAdjacency(secondVertex);
    secondVertex->createAdjacency(firstVertex);
}

void Graph::createCycleCorner(int value) {

    Vertex *vertex = searchVertex(value);

    if (vertex == nullptr) {
        cout << "Vertex not found, the cycle cannot be created!" << endl;
        return;
    }

    vertex->createAdjacency(vertex);
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

void Graph::search(SearchType searchType) {

    vector<Vertex *> vertexes = getVertexes();

    for (vector<Vertex *>::iterator it = vertexes.begin(); it != vertexes.end(); it++) {

        Vertex *vertex = *it;
        vertex->setVisited(false);
    }

    for (vector<Vertex *>::iterator it = vertexes.begin(); it != vertexes.end(); it++) {

        Vertex *vertex = *it;

        if (!vertex->getVisited()) {

            switch (searchType) {

                case DEPTH:
                    depthFirstSearch(vertex);
                    break;

                case BREADTH:
                    breadthFirstSearch(vertex);
                    break;
            }
        }
    }
}

void Graph::depthFirstSearch(Vertex *vertex) {

    vertex->setVisited(true);
    vector<Adjacency *> adjacencies = vertex->getAdjacencies();

    cout << " -> " << vertex->getValue() << endl;

    for (vector<Adjacency *>::iterator it = adjacencies.begin(); it != adjacencies.end(); it++) {

        Adjacency *adjacency = *it;
        Vertex *nextVertex = adjacency->getNext();

        if (!nextVertex->getVisited()) {

            depthFirstSearch(nextVertex);
        }
    }
}

void Graph::breadthFirstSearch(Vertex *vertex) {

    vector<Vertex *> queue;

    vertex->setVisited(true);

    cout << " -> " << vertex->getValue() << endl;

    queue.push_back(vertex);

    while (!queue.empty()) {

        Vertex *first = queue.front();
        queue.erase(queue.begin());

        vector<Adjacency *> adjacencies = first->getAdjacencies();

        for (vector<Adjacency *>::iterator it = adjacencies.begin(); it != adjacencies.end(); it++) {

            Adjacency *adjacency = *it;
            Vertex *nextVertex = adjacency->getNext();

            if (!nextVertex->getVisited()) {

                nextVertex->setVisited(true);

                cout << " -> " << nextVertex->getValue() << endl;

                queue.push_back(nextVertex);
            }
        }
    }
}
