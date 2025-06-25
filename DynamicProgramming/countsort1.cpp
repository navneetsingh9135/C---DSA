#include <iostream>
#include <algorithm> // for max()
using namespace std;

void countSort(int arr[], int n) {
    // Find the maximum value in the array
    int k = arr[0];
    for (int i = 0; i < n; i++) {
        k = max(k, arr[i]);
    }

    // Dynamically size the count array based on the max value
    int* count = new int[k + 1]();
    
    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify count array to store the cumulative counts
    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    // Create the output array to store the sorted elements
    int* output = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    // Copy sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free dynamically allocated memory
    delete[] count;
    delete[] output;
}

int main() {
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call countSort
    countSort(arr, n);

    // Display sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
