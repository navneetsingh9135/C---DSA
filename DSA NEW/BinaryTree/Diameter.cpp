#include <iostream>
#include <algorithm>
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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftHt = height(root->left);
        int rightHt = height(root->right);
        return max(leftHt, rightHt) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftDiam = diameterOfBinaryTree(root->left);
        int rightDiam = diameterOfBinaryTree(root->right);
        int currDiam = height(root->left) + height(root->right);
        return max(currDiam, max(leftDiam, rightDiam));
    }
};

// Helper function to build a sample binary tree
TreeNode* buildSampleTree() {
    // Building the tree:
    //       1
    //      / \
    //     2   3
    //    / \     
    //   4   5    
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, node2, node3);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);
    cout << "Diameter of the Binary Tree: " << diameter << endl;
    return 0;
}
