#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a, b;
        int expSum = 0, actualSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualSum += grid[i][j];
                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j]; // repeated value
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }

        expSum = (n * n) * (n * n + 1) / 2; // expected sum of 1 to n*n
        b = expSum + a - actualSum; // missing value
        ans.push_back(b);

        return ans;
    }
};

int main() {
    Solution sol;

    // Sample test case
    vector<vector<int>> grid = {
        {1, 2},
        {2, 4}
    };

    vector<int> result = sol.findMissingAndRepeatedValues(grid);

    cout << "Repeated: " << result[0] << ", Missing: " << result[1] << endl;

    return 0;
}
