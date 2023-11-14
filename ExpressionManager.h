//
//  ExpressionManager.h
//  CS303A3
//
//  Created by Brendan Clouston on 11/4/23.
//

#ifndef ExpressionManager_h
#define ExpressionManager_h

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

vector<char> getInput() {
    string userInput;
    vector<char> expression;
    cout << "Please enter an infix expression: ";
    cin >> userInput;
    for (char c : userInput) {
        expression.push_back(c);
    }
    return expression;
}

bool balancedSymbolCheck(vector<char> expressionV) {
    
    stack<char> stack1;
    for (char c : expressionV) {
        if (c == '(' || c == '[' || c == '{') {
            stack1.push(c);
        }
        else if (c == ')') {
            if (stack1.top() != '(') { return false; }
        }
        else if (c == ']') {
            if (stack1.top() != '[') { return false; }
        }
        else if (c == '}') {
            if (stack1.top() != '{') { return false; }
        }
    }
    return true;
}

int opWeight(char c) {
    if      (c == '^') { return 3; }
    else if (c == '*' || c == '/') { return 2; }
    else if (c == '+' || c == '-') { return 1; }
    else return 0;
}

string convertInfixPostfix(vector<char> prefix) {
    string postfix;
    stack<char> stack;
    for (int i = 0; i < prefix.size(); i++) {
        char c = prefix[i];
        if ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ) {
            postfix += c;
        }
        else if (c == '(') {
            stack.push('(');
        }
        else if (c == ')') {
            while (stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else {
            while (!stack.empty() && opWeight(c) <= opWeight(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}


#endif /* ExpressionManager_h */
