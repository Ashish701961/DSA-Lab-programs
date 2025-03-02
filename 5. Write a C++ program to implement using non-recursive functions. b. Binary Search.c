
#include <iostream>
using namespace std;

// Function for binary search (non-recursive)
int iterativeBinarySearch(int arr[], int size, int key) {
    int left = 0;          // Starting index
    int right = size - 1; // Ending index

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        // Check if the key is present at mid
        if (arr[mid] == key) {
            return mid; // Key found
        }
        // If the key is smaller than mid, search in the left half
        else if (arr[mid] > key) {
            right = mid - 1; // Move the right index to mid - 1
        }
        // If the key is larger than mid, search in the right half
        else {
            left = mid + 1; // Move the left index to mid + 1
        }
    }

    return -1; // Key not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int key;

    cout << "Enter the element to search for: ";
    cin >> key;

    int result = iterativeBinarySearch(arr, size, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}

