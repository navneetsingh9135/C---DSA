#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 8;
    vector<int> a = {1, 11, 2, 10, 4, 5, 2, 1};
    vector<int> forward(n, 1), backward(n, 1);

    // Compute the LIS ending at each index
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                forward[i] = max(forward[i], 1 + forward[j]);
            }
        }
    }

    // Compute the LDS starting at each index
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[i] > a[j]) {
                backward[i] = max(backward[i], 1 + backward[j]);
            }
        }
    }

    // Combine LIS and LDS to find the LBS
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, forward[i] + backward[i] - 1);
    }

    cout << ans << endl;
    return 0;
}
