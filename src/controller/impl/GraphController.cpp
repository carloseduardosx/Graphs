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

int GraphController::treatCreateWeightOption() {

    int answer = treatInput(getConsoleLine());

    switch (answer) {
        case 1:
            cout << "Type the weight you want add: ";
            return treatInput(getConsoleLine());

        case 2:
            return noWeight;

        default:
            cout << "Please, type a valid answer!" << endl;
            return treatCreateWeightOption();
    }
}

void GraphController::validateAndUpdateAllWeight(int weight) {

    if (weight != noWeight && weight != invalid_option) {
        graph->search(graph->WEIGHT);
    }
}

int GraphController::checkWeightedGraph() {

    string currentGraphType = graph->currentGraphType();

    if (currentGraphType.find("weighted") != string::npos) {
        return 0;
    } else {
        return noWeight;
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
            cout << "Did you want add a weight in the corner?" << endl;
            cout << "1- Yes" << " <==> " << "2- No" << endl;
            int weight = treatCreateWeightOption();

            if (isNotValidValue(firstValue) || isNotValidValue(secondOption) || isNotValidValue(weight)) {
                cout << "Cannot create that connection, because one or more of values are invalids!";
                break;
            }

            if (weight == noWeight) {
                weight = checkWeightedGraph();
            }

            graph->createCorner(firstValue, secondValue, weight);
            validateAndUpdateAllWeight(weight);
            break;
        }

        case thirdOption: {

            showAdjacencies();

            cout << endl << endl;
            cout << "Write what vertex should be created the cycle: " << endl;
            int value = treatInput(getConsoleLine());
            cout << "Did you want add a weight in the corner?" << endl;
            cout << "1- Yes" << " <==> " << "2- No" << endl;
            int weight = treatCreateWeightOption();

            if (isNotValidValue(value) || isNotValidValue(weight)) {
                cout << "Cannot create that cycle, because the value or weight are invalid!";
                break;
            }
            if (weight == noWeight) {
                weight = checkWeightedGraph();
            }

            graph->createCycleCorner(value, weight);
            validateAndUpdateAllWeight(weight);
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
            cout << "Did you want add a weight in the corner?" << endl;
            cout << "1- Yes" << " <==> " << "2- No" << endl;
            int weight = treatCreateWeightOption();

            if (isNotValidValue(from) || isNotValidValue(to) || isNotValidValue(weight)) {
                cout << "Cannot create that connection, because one or more of values are invalids!";
                break;
            }
            if (weight == noWeight) {
                weight = checkWeightedGraph();
            }

            graph->createConvergentCorner(from, to, weight);
            validateAndUpdateAllWeight(weight);
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
            cout << "Did you want add a weight in the corner?" << endl;
            cout << "1- Yes" << " <==> " << "2- No" << endl;
            int weight = treatCreateWeightOption();

            if (isNotValidValue(from) || isNotValidValue(to) || isNotValidValue(weight)) {
                cout << "Cannot create that connection, because one or more of values are invalids!";
                break;
            }
            if (weight == noWeight) {
                weight = checkWeightedGraph();
            }

            graph->createDivergentCorner(from, to, weight);
            validateAndUpdateAllWeight(weight);
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
