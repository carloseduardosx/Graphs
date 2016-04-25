#include "../Adjacency.h"

Corner *Adjacency::getCorner() {

    return this->corner;
}

void Adjacency::setCorner(Corner *corner) {

    this->corner = corner;
}

Vertex *Adjacency::getNext() {

    return this->next;
}

void Adjacency::setNext(Vertex *next) {

    this->next = next;
}