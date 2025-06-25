#include <iostream>
#include <vector>
#include <algorithm> // For max
using namespace std;

int main() {
    int n = 5, W = 11;
    vector<int> val = {3, 2, 4, 5, 1}; // Values of items
    vector<int> wt = {4, 3, 5, 6, 1};  // Weights of items
    vector<int> dp(W + 1, 0);          // DP array to store max values for each weight

    // Unbounded knapsack logic
    for (int j = 0; j <= W; j++) {
        for (int i = 0; i < n; i++) {
            if (j >= wt[i]) { // Check if the current weight fits
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
            }
        }
    }

    cout << "Maximum value for weight " << W << " is: " << dp[W] << endl;
    return 0;
}
  