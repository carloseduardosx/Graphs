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

void Graph::createCorner(int firstValue, int secondValue, int weight) {

    vector<Vertex *> firstVertexes = searchVertex(firstValue);
    vector<Vertex *> secondVertexes = searchVertex(secondValue);

    if (firstVertexes.empty() || secondVertexes.empty()) {
        cout << "One or both vertexes not found, the corner cannot be created!" << endl;
        return;
    }

    if (firstVertexes.size() == 1 && secondVertexes.size() == 1) {

        Vertex *firstVertex = firstVertexes.front();
        Vertex *secondVertex = secondVertexes.front();

        firstVertex->createAdjacency(secondVertex, weight);
        secondVertex->createAdjacency(firstVertex, weight);
    } else {

        for (vector<Vertex *>::iterator it = firstVertexes.begin(); it != firstVertexes.end(); it++) {

            Vertex *firstVertex = *it;

            for (vector<Vertex *>::iterator secondIt = secondVertexes.begin();
                 secondIt != secondVertexes.end(); secondIt++) {

                Vertex *secondVertex = *secondIt;

                firstVertex->createAdjacency(secondVertex, weight);
                secondVertex->createAdjacency(firstVertex, weight);
            }
        }
    }
}

void Graph::createCycleCorner(int value, int weight) {

    vector<Vertex *> vertexes = searchVertex(value);

    if (vertexes.empty()) {
        cout << "Vertex not found, the cycle cannot be created!" << endl;
        return;
    }

    if (vertexes.size() == 1) {

        Vertex *vertex = vertexes.front();

        vertex->createCycleAdjacency(vertex, weight);
    } else {

        for (vector<Vertex *>::iterator it = vertexes.begin(); it != vertexes.end(); it++) {

            Vertex *vertex = *it;

            vertex->createCycleAdjacency(vertex, weight);
        }
    }
}

void Graph::createConvergentCorner(int from, int to, int weight) {

    vector<Vertex *> fromVertexes = searchVertex(from);
    vector<Vertex *> toVertexes = searchVertex(to);

    if (fromVertexes.empty() || toVertexes.empty()) {
        cout << "One or both vertexes not found, the corner cannot be created!" << endl;
        return;
    }

    if (fromVertexes.size() == 1 && toVertexes.size() == 1) {

        Vertex *fromVertex = fromVertexes.front();
        Vertex *toVertex = toVertexes.front();

        fromVertex->createConvergentAdjacency(toVertex, weight);
    } else {

        for (vector<Vertex *>::iterator it = fromVertexes.begin(); it != fromVertexes.end(); it++) {

            Vertex *fromVertex = *it;

            for (vector<Vertex *>::iterator secondIt = toVertexes.begin(); secondIt != toVertexes.end(); secondIt++) {

                Vertex *toVertex = *secondIt;

                fromVertex->createConvergentAdjacency(toVertex, weight);
            }
        }
    }
}

void Graph::createDivergentCorner(int from, int to, int weight) {

    createConvergentCorner(to, from, weight);
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

string Graph::currentGraphType() {

    int count = 0;
    bool weighted = false;
    bool directional = false;
    bool pseudoGraph = false;
    string graphTypes = "This graph is: ";

    vector<Vertex *> vertexes = getVertexes();

    for (vector<Vertex *>::iterator it = vertexes.begin(); it != vertexes.end(); it++) {

        Vertex *vertex = *it;
        vector<Adjacency *> adjacencies = vertex->getAdjacencies();

        for (vector<Adjacency *>::iterator secondIt = adjacencies.begin(); secondIt != adjacencies.end(); secondIt++) {

            Adjacency *adjacency = *secondIt;
            Corner *corner = adjacency->getCorner();
            Vertex *convergent = corner->getConvergent();
            Vertex *divergent = corner->getDivergent();

            if (!weighted && corner->getWeight() != -1) {
                weighted = true;
            }
            if (!pseudoGraph && corner->isCycle()) {
                pseudoGraph = true;
            }
            if (!directional && (convergent == nullptr || divergent == nullptr)) {
                directional = true;
            }
            count++;
        }
    }

    if (directional) {

        graphTypes += " -> directional";
    }
    if (!directional && count != 0) {
        graphTypes += " -> not directional";
    }
    if (weighted) {

        graphTypes += " -> weighted";
    }
    if (pseudoGraph) {

        graphTypes += " -> pseudoGraph";
    }
    if (count == 0) {

        graphTypes += " -> null graph";
    }

    return graphTypes;
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

                case WEIGHT:
                    updateAllWeight(vertex);
            }
        }
    }
}

void Graph::depthFirstSearch(Vertex *vertex) {

    vertex->setVisited(true);
    vector<Adjacency *> adjacencies = vertex->getAdjacencies();

    vertex->showGeneratorTree();

    for (vector<Adjacency *>::iterator it = adjacencies.begin(); it != adjacencies.end(); it++) {

        Adjacency *adjacency = *it;

        Vertex *nextVertex = adjacency->getCorner()->getConvergent();

        if (!nextVertex->getVisited()) {
            depthFirstSearch(nextVertex);
        }
    }
}

void Graph::breadthFirstSearch(Vertex *vertex) {

    vector<Vertex *> queue;

    vertex->setVisited(true);
    vertex->showGeneratorTree();
    queue.push_back(vertex);

    while (!queue.empty()) {

        Vertex *first = queue.front();

        queue.erase(queue.begin());

        vector<Adjacency *> adjacencies = first->getAdjacencies();

        for (vector<Adjacency *>::iterator it = adjacencies.begin(); it != adjacencies.end(); it++) {

            Adjacency *adjacency = *it;
            Vertex *nextVertex = adjacency->getCorner()->getConvergent();

            if (!nextVertex->getVisited()) {

                nextVertex->setVisited(true);
                nextVertex->showGeneratorTree();
                queue.push_back(nextVertex);
            }
        }
    }
}

void Graph::updateAllWeight(Vertex *vertex) {

    vector<Adjacency *> adjacencies = vertex->getAdjacencies();

    for (vector<Adjacency *>::iterator it = adjacencies.begin(); it != adjacencies.end(); it++) {

        Adjacency *adjacency = *it;

        Corner *corner = adjacency->getCorner();

        if (corner->getWeight() == -1) {
            corner->setWeight(0);
        }
    }
}