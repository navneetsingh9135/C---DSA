#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            int first = arr[i];
            int sec = tar - first;
            if (m.find(sec) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }
            m[first] = i;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }

    return 0;
}
