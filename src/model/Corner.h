#ifndef GRAPH_ALGORITHMS_CORNER_H
#define GRAPH_ALGORITHMS_CORNER_H

class Vertex;

class Corner {

private:

    int weight = -1;
    bool cycle = false;
    Vertex *divergent;
    Vertex *convergent;

public:

    int getWeight();

    void setWeight(int weight);

    bool isCycle();

    void setCycle(bool cycle);

    Vertex *getDivergent();

    void setDivergent(Vertex *divergent);

    Vertex *getConvergent();

    void setConvergent(Vertex *convergent);
};

#endif