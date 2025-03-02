#include <iostream>
using namespace std;

// Recursive function for binary search
int recursiveBinarySearch(int arr[], int left, int right, int key) {
    // Base case: if the left index exceeds the right index, the key is not found
    if (left > right) {
        return -1;
    }

    // Calculate the middle index
    int mid = left + (right - left) / 2;

    // Check if the key is present at mid
    if (arr[mid] == key) {
        return mid; // Key found
    }
    // If the key is smaller than mid, search in the left half
    else if (arr[mid] > key) {
        return recursiveBinarySearch(arr, left, mid - 1, key);
    }
    // If the key is larger than mid, search in the right half
    else {
        return recursiveBinarySearch(arr, mid + 1, right, key);
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the element to search for: ";
    cin >> key;

    int result = recursiveBinarySearch(arr, 0, size - 1, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
