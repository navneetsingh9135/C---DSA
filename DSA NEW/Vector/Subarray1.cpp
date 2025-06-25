#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum == k) count++;
            }
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
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum (k): ";
    cin >> k;

    Solution sol;
    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays that sum to " << k << " is: " << result << endl;

    return 0;
}
