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

    vector<Vertex *> firstVertexes = searchVertex(firstValue);
    vector<Vertex *> secondVertexes = searchVertex(secondValue);

    if (firstVertexes.empty() || secondVertexes.empty()) {
        cout << "One or both vertexes not found, the corner cannot be created!" << endl;
        return;
    }

    if (firstVertexes.size() == 1 && secondVertexes.size() == 1) {

        Vertex *firstVertex = firstVertexes.front();
        Vertex *secondVertex = secondVertexes.front();

        firstVertex->createAdjacency(secondVertex);
        secondVertex->createAdjacency(firstVertex);
    } else {

        for (vector<Vertex *>::iterator it = firstVertexes.begin(); it != firstVertexes.end(); it++) {

            Vertex *firstVertex = *it;

            for (vector<Vertex *>::iterator secondIt = secondVertexes.begin(); secondIt != secondVertexes.end(); secondIt++) {

                Vertex *secondVertex = *secondIt;

                firstVertex->createAdjacency(secondVertex);
                secondVertex->createAdjacency(firstVertex);
            }
        }
    }
}

void Graph::createCycleCorner(int value) {

    vector<Vertex *> vertexes = searchVertex(value);

    if (vertexes.empty()) {
        cout << "Vertex not found, the cycle cannot be created!" << endl;
        return;
    }

    if (vertexes.size() == 1) {

        Vertex *vertex = vertexes.front();

        vertex->createAdjacency(vertex);
    } else {

        for (vector<Vertex *>::iterator it = vertexes.begin(); it != vertexes.end(); it++) {

            Vertex *vertex = *it;

            vertex->createAdjacency(vertex);
        }
    }
}

void Graph::showVertexes() {

    vector<Vertex *> vertexes = getVertexes();

    for (vector<Vertex *>::iterator it = vertexes.begin(); it != vertexes.end(); it++) {

        Vertex *vertex = *it;

        cout << vertex->getValue() << endl;
    }
}

vector<Vertex *> Graph::searchVertex(int value) {

    vector<Vertex *> vertexes = getVertexes();
    vector<Vertex *> foundedVertexes;

    for (vector<Vertex *>::iterator it = vertexes.begin(); it != vertexes.end(); it++) {

        Vertex *vertex = *it;

        if (vertex->getValue() == value) {
            foundedVertexes.push_back(vertex);
        }
    }

    return foundedVertexes;
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