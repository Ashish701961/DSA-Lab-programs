#include <iostream>
using namespace std;

#define MAX_SIZE 100  // Maximum size of Stack

class Stack {
private:
    int arr[MAX_SIZE]; // Array to store stack elements
    int top;           // Top of the stack

public:
    Stack() { top = -1; } // Constructor initializes top to -1

    // Function to push an element onto the stack
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    // Function to pop an element from the stack
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    // Function to return the top element without removing it
    int peek() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }

    // Function to check if the stack is full
    bool isFull() {
        return (top >= MAX_SIZE - 1);
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Top element after pop: " << stack.peek() << endl;

    return 0;
}
