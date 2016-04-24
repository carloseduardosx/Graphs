#ifndef GRAPHS_GRAPHCONTROLLER_H
#define GRAPHS_GRAPHCONTROLLER_H

#include <iostream>

using namespace std;

class GraphController {

private:

    int success_status = 0;
    int invalid_option = -1;
    string divider = "-------------------------------------------------";
    string project = "Graphs";
    string firstOption = "1- Insert Vertex";
    string secondOption = "2- Create Corner";
    string thirdOption = "3- Show Graph";
    string fourthOption = "4- Exit";
    string selectOption = "Select a option: ";

    string getConsoleLine();

    int treatOptionSelect(string option);

    void executeAction(string option);

    void cleanConsole();

public:

    void printOptions();
};

#endif