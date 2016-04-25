#ifndef GRAPHS_GRAPHCONTROLLER_H
#define GRAPHS_GRAPHCONTROLLER_H

#include <iostream>
#include "../model/Graph.h"

using namespace std;

class GraphController {

private:

    int success_status = 0;
    int invalid_option = -1;
    string divider = "-------------------------------------------------";
    string project = "Graphs";
    string firstOption = "1- Insert Vertex";
    string secondOption = "2- Create Corner";
    string thirdOption = "3- Show Vertexes";
    string fourthOption = "4- Show adjacency lists";
    string fifthOption = "5- Depth-First Search";
    string sixthOption = "6- Breadth-First Search";
    string seventhOption = "7- Exit";
    string selectOption = "Select a option: ";
    Graph *graph = new Graph();

    string getConsoleLine();

    int treatInput(string option);

    void executeAction(string option);

    void cleanConsole();

    bool isNotValidValue(int value);

public:

    void printOptions();
};

#endif