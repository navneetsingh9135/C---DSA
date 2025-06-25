#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        
        while (!q.empty()) {
            int currLevelSize = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;
            maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

            for (int i = 0; i < currLevelSize; i++) {
                auto curr = q.front(); q.pop();
                unsigned long long idx = curr.second - stIdx; // normalize index
                if (curr.first->left) {
                    q.push({curr.first->left, idx * 2 + 1});
                }
                if (curr.first->right) {
                    q.push({curr.first->right, idx * 2 + 2});
                }
            }
        }
        return maxWidth;
    }
};

// Helper function to build a sample binary tree
TreeNode* buildSampleTree() {
    /*
           1
         /   \
        3     2
       / \     \ 
      5   3     9

      Expected Width = 4 (between nodes 5 and 9)
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    return root;
}

// Main function
int main() {
    TreeNode* root = buildSampleTree();
    Solution sol;
    int width = sol.widthOfBinaryTree(root);
    cout << "Maximum Width of Binary Tree: " << width << endl;
    return 0;
}
