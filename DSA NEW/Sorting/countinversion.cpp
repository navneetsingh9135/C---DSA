#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            invCount += (mid - i + 1); // Count inversions
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= end) temp.push_back(arr[j++]);

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }

    return invCount;
}

int mergeSort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;
        int leftInvCount = mergeSort(arr, st, mid);       // FIXED
        int rightInvCount = mergeSort(arr, mid + 1, end);  // FIXED
        int mergeInvCount = merge(arr, st, mid, end);
        return leftInvCount + rightInvCount + mergeInvCount;
    }
    return 0;
}

int main() {
    vector<int> arr = {6, 3, 5, 2, 7};
    int ans = mergeSort(arr, 0, arr.size() - 1);
    cout << "inv count: " << ans << endl;
    return 0;
}
