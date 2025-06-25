#include <iostream>
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
    bool isIdentical(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) {
            return p == q;
        }
        return p->val == q->val 
            && isIdentical(p->left, q->left) 
            && isIdentical(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) {
            return false;
        }
        if(root->val == subRoot->val && isIdentical(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) 
            || isSubtree(root->right, subRoot);
    }
};

int main() {
    // Main tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // Subtree
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;
    if(sol.isSubtree(root, subRoot)) {
        cout << "subRoot is a subtree of root" << endl;
    } else {
        cout << "subRoot is NOT a subtree of root" << endl;
    }

    // Cleanup memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    delete subRoot->left;
    delete subRoot->right;
    delete subRoot;

    return 0;
}
