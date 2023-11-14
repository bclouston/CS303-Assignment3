//
//  main.cpp
//  CS303A3
//
//  Created by Brendan Clouston on 11/4/23.
//

#include "ExpressionManager.h"

int menu() {
    string input;
    while (true) {
        cout << "MENU:" << endl;
        cout << "1: Convert infix expression to postfix" << endl;
        cout << "2: Check function for balanced symbols" << endl;
        cout << "3: Exit" << endl << endl;
        cout << "Please enter 1-3 to choose an option: ";
        cin >> input;
        return stoi(input);
    }
}

int main() {
    vector<char> expression;
    string postfix;
    string userinput;
    int menu1;
    while (true) {
        menu1 = menu();
        if (menu1 == 1) {
            expression = getInput();
            postfix = convertInfixPostfix(expression);
            cout << endl << "Result: " << postfix << endl;
        }
        else if (menu1 == 2) {
            expression = getInput();
            if (balancedSymbolCheck(expression) == false) {
                cout << "Unbalanced symbol check failed" << endl << endl;
            }
            else {
                cout << "Unbalanced symbol check passed" << endl << endl;
            }
        }
        else if (menu1 == 3) {
            return 0;
        }
        cout << "Would you like to try again? (Y/N): ";
        cin >> userinput;
        if (userinput[0] == 'N') {
            return 0;
        }
    }
    return 0;
}
