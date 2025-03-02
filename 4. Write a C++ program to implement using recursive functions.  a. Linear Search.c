
#include <iostream>
using namespace std;

// Recursive function for linear search
int recursiveLinearSearch(int arr[], int size, int key, int index = 0) {
    // Base case: if index reaches the size of the array, return -1 (not found)
    if (index >= size) {
        return -1;
    }
    // If the current element matches the key, return the index
    if (arr[index] == key) {
        return index;
    }
    // Recursive case: search in the next index
    return recursiveLinearSearch(arr, size, key, index + 1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the element to search for: ";
    cin >> key;

    int result = recursiveLinearSearch(arr, size, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
