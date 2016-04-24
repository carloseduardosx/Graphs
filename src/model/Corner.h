#ifndef GRAPH_ALGORITHMS_CORNER_H
#define GRAPH_ALGORITHMS_CORNER_H

class Vertex;
class Corner {

private:

    int weight;
    Vertex *divergent;
    Vertex *convergent;

public:

    int getWeight();

    void setWeight(int weight);

    Vertex* getDivergent();

    void setDivergent(Vertex *divergent);

    Vertex* getConvergent();

    void setConvergent(Vertex *convergent);
};

#endif
