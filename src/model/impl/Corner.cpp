#include "../Corner.h"

int Corner::getWeight() {

    return this->weight;
}

void Corner::setWeight(int weight) {

    this->weight = weight;
}

bool Corner::isCycle() {
    return this->cycle;
}

void Corner::setCycle(bool cycle) {
    this->cycle = cycle;
}

Vertex *Corner::getDivergent() {

    return this->divergent;
}

void Corner::setDivergent(Vertex *divergent) {

    this->divergent = divergent;
}

Vertex *Corner::getConvergent() {

    return this->convergent;
}

void Corner::setConvergent(Vertex *convergent) {

    this->convergent = convergent;
}