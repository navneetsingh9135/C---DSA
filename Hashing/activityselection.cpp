#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        v[i] = {start, end};
    }

    // Sort intervals based on their end time
    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int take = 0;  // To count the number of non-overlapping intervals
    int end = -1;  // To keep track of the end time of the last added interval

    for (int i = 0; i < n; i++) {
        // If the current interval starts after or when the last added interval ends
        if (v[i][0] >= end) {
            take++;          // Count this interval
            end = v[i][1];  // Update the end time to the current interval's end
        }
    }

    cout << take << endl;
    return 0;
}
