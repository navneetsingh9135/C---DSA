#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* helper(vector<int>& nums, int st, int end) {
        if (st > end) {
            return nullptr;
        }
        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, st, mid - 1);
        root->right = helper(nums, mid + 1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

// Function to print inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution sol;
    TreeNode* bstRoot = sol.sortedArrayToBST(nums);

    cout << "Inorder traversal of BST: ";
    inorderTraversal(bstRoot);
    cout << endl;

    return 0;
}
