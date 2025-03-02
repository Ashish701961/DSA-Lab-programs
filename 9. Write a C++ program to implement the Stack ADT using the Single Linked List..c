#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node

    Node(int value) : data(value), next(nullptr) {} // Constructor
};

// Class for Stack
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor
    Stack() : top(nullptr) {} // Initialize top to nullptr

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop(); // Pop all elements to free memory
        }
    }

    // Function to add an item to the stack
    void push(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = top; // Link new node to the previous top
        top = newNode; // Update top to the new node
        cout << value << " pushed to stack." << endl;
    }

    // Function to remove an item from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop from empty stack." << endl;
            return -1; // Return -1 to indicate stack is empty
        }
        int poppedValue = top->data; // Get the top value
        Node* temp = top; // Temporary pointer to the top node
        top = top->next; // Update top to the next node
        delete temp; // Free the memory of the popped node
        return poppedValue; // Return the popped value
    }

    // Function to return the top item of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot peek." << endl;
            return -1; // Return -1 to indicate stack is empty
        }
        return top->data; // Return the top value
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr; // True if top is nullptr
    }
};

int main() {
    Stack stack; // Create a Stack object

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;

    cout << stack.pop() << " popped from stack." << endl;
    cout << stack.pop() << " popped from stack." << endl;

    cout << "Top element is: " << stack.peek() << endl;

    cout << stack.pop() << " popped from stack." << endl;
    cout << stack.pop() << " popped from stack." << endl; // This will show stack underflow

    return 0;
}
