#include "../GraphController.h"

void GraphController::printOptions() {

    cout << divider << endl;
    cout << project << endl;
    cout << divider << endl << endl;
    cout << firstOption << endl;
    cout << secondOption << endl;
    cout << thirdOption << endl;
    cout << fourthOption << endl << endl;
    cout << selectOption;

    executeAction(getConsoleLine());
}

string GraphController::getConsoleLine() {

    string option;
    getline(cin, option);

    return option;
}

int GraphController::treatOptionSelect(string option) {

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

    const int parsedOption = treatOptionSelect(option);

    const int firstOption = 1;
    const int secondOption = 2;
    const int thirdOption = 3;
    const int fourthOption = 4;

    cleanConsole();

    switch (parsedOption) {

        case firstOption:
            cout << "First option selected!" << endl;
            break;

        case secondOption:
            cout << "Second option selected!" << endl;
            break;

        case thirdOption:
            cout << "Third option selected!" << endl;
            break;

        case fourthOption:
            exit(success_status);

        default:
            cout << "Invalid option selected!" << endl;
            break;
    }

    printOptions();
}
