#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // Edge case: Empty array

        vector<int> lmax(n, 0), rmax(n, 0);
        lmax[0] = height[0];
        rmax[n - 1] = height[n - 1];

        // Compute left max for each index
        for (int i = 1; i < n; i++) {
            lmax[i] = max(lmax[i - 1], height[i]);
        }

        // Compute right max for each index
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = max(rmax[i + 1], height[i]);
        }

        int ans = 0;
        // Calculate trapped water at each index
        for (int i = 0; i < n; i++) {
            ans += min(lmax[i], rmax[i]) - height[i];
        }

        return ans;
    }
};

// Main function to test the trapping rainwater function
int main() {
    Solution sol;

    // Example test cases
    vector<vector<int>> testCases = {
        {0,1,0,2,1,0,1,3,2,1,2,1},  // Expected output: 6
        {4,2,0,3,2,5},              // Expected output: 9
        {3, 0, 2, 0, 4},            // Expected output: 7
        {1, 1, 1, 1, 1},            // Expected output: 0
        {5,4,3,2,1},                // Expected output: 0
        {}                          // Edge case: Empty input, Expected output: 0
    };

    for (auto& height : testCases) {
        cout << "Trapped Rainwater: " << sol.trap(height) << endl;
    }

    return 0;
}
