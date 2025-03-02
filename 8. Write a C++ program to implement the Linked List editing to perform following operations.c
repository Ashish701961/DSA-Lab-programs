#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }

    // Insert a new element at the end
    void insert(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << value << " into the list." << endl;
    }

    // Delete an element from the list
    void remove(int value) {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << " from the list." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            cout << "Deleted " << value << " from the list." << endl;
        } else {
            cout << "Element not found!" << endl;
        }
    }

    // Search for a key element in the list
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Element " << key << " found in the list." << endl;
                return true;
            }
            temp = temp->next;
        }
        cout << "Element " << key << " not found in the list." << endl;
        return false;
    }

    // Count the number of nodes in the list
    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();

    list.remove(20);
    list.display();

    list.search(30);
    list.search(40);

    cout << "Number of nodes: " << list.countNodes() << endl;

    return 0;
}
