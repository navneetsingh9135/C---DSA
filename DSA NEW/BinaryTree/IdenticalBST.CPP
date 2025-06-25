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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL){
            return p == q;
        }
        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);
        return isLeftSame && isRightSame && p->val == q->val;
    }
};

int main() {
    // Tree 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // Tree 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    Solution sol;
    if(sol.isSameTree(root1, root2)) {
        cout << "Both trees are identical." << endl;
    } else {
        cout << "Trees are NOT identical." << endl;
    }

    // Cleanup memory
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
