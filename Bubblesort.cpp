#include <iostream>
using namespace std;

// Function to implement Bubble Sort
void bubbleSort(int arr[], int n) {
    // Traverse through all elements in the array
    for (int i = 0; i < n - 1; i++) {
        cout << "Pass " << i + 1 << ": ";
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        // Print the array after each pass to see the sorting progress
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
