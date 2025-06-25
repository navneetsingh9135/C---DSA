#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1; // Size of left temporary array
    int n2 = r - mid;     // Size of right temporary array

    int a[n1], b[n2];     // Temporary arrays

    // Copy elements into temporary arrays
    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
    }

    // Merge the two arrays back into the original array
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of the left array
    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++; 
    }

    // Copy any remaining elements of the right array
    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2; // To prevent overflow
        mergeSort(arr, l, mid);   // Sort first half
        mergeSort(arr, mid + 1, r); // Sort second half
        merge(arr, l, mid, r);    // Merge the two halves
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
