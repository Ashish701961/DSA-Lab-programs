#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // For non-operators
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> operators; // Stack to hold operators
    string postfix; // Resulting postfix expression

    for (char token : infix) {
        // If the token is an operand (number or letter), add it to the output
        if (isalnum(token)) {
            postfix += token;
            postfix += ' '; // Add space for separation
        }
        // If the token is '(', push it to the stack
        else if (token == '(') {
            operators.push(token);
        }
        // If the token is ')', pop from the stack to the output until '(' is found
        else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.pop(); // Pop the '('
        }
        // If the token is an operator
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(token); // Push the current operator onto the stack
        }
    }

    // Pop all the remaining operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Enter an infix expression: ";
    getline(cin, infix); // Read the entire line

    string postfix = infixToPostfix(infix);
    cout << "The postfix expression is: " << postfix << endl;

    return 0;
}
