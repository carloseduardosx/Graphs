#ifndef GRAPHS_ADJACENCY_H
#define GRAPHS_ADJACENCY_H


class Vertex;

class Corner;

class Adjacency {

private:

    Corner *corner;

public:

    Corner *getCorner();

    void setCorner(Corner *corner);
};

#endif