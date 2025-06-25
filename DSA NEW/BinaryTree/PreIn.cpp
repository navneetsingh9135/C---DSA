#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
        if (left > right) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preIdx]);
        int inIdx = search(inorder, left, right, preorder[preIdx]);
        preIdx++;
        root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};

// Helper function to print tree in inorder fashion (for verification)
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Helper function to print tree in preorder fashion (for verification)
void printPreorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);
    
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;
    
    cout << "Preorder traversal of the constructed tree: ";
    printPreorder(root);
    cout << endl;
    
    return 0;
}
