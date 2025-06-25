#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;
        vector<int> prefixSum(n, 0);
        prefixSum[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        unordered_map<int, int> m;

        for (int j = 0; j < n; j++) {
            if (prefixSum[j] == k) count++;

            int val = prefixSum[j] - k;
            if (m.find(val) != m.end()) {
                count += m[val];
            }

            // Initialize the map if not found
            if (m.find(prefixSum[j]) == m.end()) {
                m[prefixSum[j]] = 0;
            }

            m[prefixSum[j]]++;
        }

        return count;
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum (k): ";
    cin >> k;

    Solution sol;
    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays that sum to " << k << " is: " << result << endl;

    return 0;
}
