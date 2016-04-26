#include "../GraphController.h"

void GraphController::printOptions() {

    cout << divider << endl;
    cout << project << endl;
    cout << divider << endl << endl;
    cout << firstOption << endl;
    cout << secondOption << endl;
    cout << thirdOption << endl;
    cout << fourthOption << endl;
    cout << fifthOption << endl;
    cout << sixthOption << endl;
    cout << seventhOption << endl;
    cout << eightOption << endl;
    cout << ninthOption << endl;
    cout << tenthOption << endl;
    cout << eleventhOption << endl << endl;
    cout << selectOption;

    executeAction(getConsoleLine());
}

string GraphController::getConsoleLine() {

    string option;
    getline(cin, option);

    return option;
}

int GraphController::treatInput(string option) {

    try {
        return stoi(option);
    } catch (invalid_argument e) {
        return invalid_option;
    } catch (out_of_range e) {
        return invalid_option;
    }
}

void GraphController::cleanConsole() {
    system("clear");
}

void GraphController::showAdjacencies() {

    vector<Vertex *> vertexes = graph->getVertexes();

    for (vector<Vertex *>::iterator it = vertexes.begin(); it != vertexes.end(); it++) {
        Vertex *vertex = *it;
        vertex->showAdjacencies();
    }
}

void GraphController::executeAction(string option) {

    const int parsedOption = treatInput(option);

    const int firstOption = 1;
    const int secondOption = 2;
    const int thirdOption = 3;
    const int fourthOption = 4;
    const int fifthOption = 5;
    const int sixthOption = 6;
    const int seventhOption = 7;
    const int eightOption = 8;
    const int ninthOption = 9;
    const int tenthOption = 10;
    const int eleventhOption = 11;

    cleanConsole();

    switch (parsedOption) {

        case firstOption: {

            graph->showVertexes();

            cout << endl << endl;
            cout << "Type a value to the vertex: ";

            int value = treatInput(getConsoleLine());

            if (isNotValidValue(value)) {
                cout << "Cannot assign de value to the vertex!" << endl;
                break;
            }
            graph->createVertex(value);
            break;
        }

        case secondOption: {

            showAdjacencies();

            cout << endl << endl;
            cout << "Write what vertexes should be connected: " << endl;
            cout << "First Vertex: ";
            int firstValue = treatInput(getConsoleLine());
            cout << "Second Vertex: ";
            int secondValue = treatInput(getConsoleLine());

            if (isNotValidValue(firstValue) || isNotValidValue(secondOption)) {
                cout << "Cannot create that connection, because one or both of values are invalids!";
                break;
            }
            graph->createCorner(firstValue, secondValue);
            break;
        }

        case thirdOption: {

            showAdjacencies();

            cout << endl << endl;
            cout << "Write what vertex should be created the cycle: " << endl;

            int value = treatInput(getConsoleLine());

            if (isNotValidValue(value)) {
                cout << "Cannot create that cycle, because the value are invalid!";
                break;
            }
            graph->createCycleCorner(value);
            break;
        }

        case fourthOption: {

            showAdjacencies();

            cout << endl << endl;
            cout << "Adding convergent corner:" << endl;
            cout << "From: ";
            int from = treatInput(getConsoleLine());
            cout << "To: ";
            int to = treatInput(getConsoleLine());

            if (isNotValidValue(from) || isNotValidValue(to)) {
                cout << "Cannot create that connection, because one or both of values are invalids!";
                break;
            }
            graph->createConvergentCorner(from, to);
            break;
        }

        case fifthOption: {

            showAdjacencies();

            cout << endl << endl;
            cout << "Adding divergent corner:" << endl;
            cout << "From: ";
            int from = treatInput(getConsoleLine());
            cout << "To: ";
            int to = treatInput(getConsoleLine());

            if (isNotValidValue(from) || isNotValidValue(to)) {
                cout << "Cannot create that connection, because one or both of values are invalids!";
                break;
            }
            graph->createDivergentCorner(from, to);
            break;
        }

        case sixthOption: {
            graph->showVertexes();
            break;
        }

        case seventhOption: {

            showAdjacencies();
            break;
        }

        case eightOption: {
            cout << graph->currentGraphType() << endl;
            break;
        }

        case ninthOption: {
            graph->search(graph->DEPTH);
            break;
        }

        case tenthOption: {
            graph->search(graph->BREADTH);
            break;
        }

        case eleventhOption: {
            exit(success_status);
        }

        default: {
            cout << "Invalid option selected!" << endl;
            break;
        }
    }
    printOptions();
}

bool GraphController::isNotValidValue(int value) {

    return value == invalid_option;
}
