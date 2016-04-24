#ifndef GRAPHS_ADJACENCY_H
#define GRAPHS_ADJACENCY_H


class Vertex;
class Corner;
class Adjacency {

private:

    Vertex *next;
    Corner *corner;

public:

    Vertex *getNext();

    void setNext(Vertex *next);

    Corner *getCorner();

    void setCorner(Corner *corner);

};

#endif
