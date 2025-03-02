
#include <iostream>
using namespace std;

#define MAX_SIZE 100  // Maximum size of Queue

class Queue {
private:
    int arr[MAX_SIZE]; // Array to store queue elements
    int front, rear;   // Front and Rear pointers

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0; // Initialize front
        arr[++rear] = value;
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int value = arr[front++];
        return value;
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.peek() << endl;
    cout << "Dequeued element: " << queue.dequeue() << endl;
    cout << "Front element after dequeue: " << queue.peek() << endl;

    return 0;
}

