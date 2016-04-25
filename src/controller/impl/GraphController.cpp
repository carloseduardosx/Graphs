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
    cout << eightOption << endl << endl;
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

    cleanConsole();

    switch (parsedOption) {

        case firstOption: {

            cout << "Type a value to the vertex: ";

            int value = treatInput(getConsoleLine());

            if (isNotValidValue(value)) {
                cout << "Cannot assign de value to the vertex!";
                break;
            }

            graph->createVertex(value);
            break;
        }

        case secondOption: {

            cout << "Write what vertexes should be connected: " << endl;

            int firstValue = treatInput(getConsoleLine());
            int secondValue = treatInput(getConsoleLine());

            if (isNotValidValue(firstValue) || isNotValidValue(secondOption)) {
                cout << "Cannot create that connection, because one or both of values are invalids!";
                break;
            }

            graph->createCorner(firstValue, secondValue);
            break;
        }

        case thirdOption: {

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
            graph->showVertexes();
            break;
        }

        case fifthOption: {

            vector<Vertex *> vertexes = graph->getVertexes();

            for (vector<Vertex *>::iterator it = vertexes.begin(); it != vertexes.end(); it++) {
                Vertex *vertex = *it;
                vertex->showAdjacencies();
            }
            break;
        }

        case sixthOption: {
            graph->search(graph->DEPTH);
            break;
        }

        case seventhOption: {
            graph->search(graph->BREADTH);
            break;
        }

        case eightOption: {
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
