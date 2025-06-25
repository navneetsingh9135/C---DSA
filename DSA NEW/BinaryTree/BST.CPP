#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Inorder Traversal (Left, Root, Right)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
    
    // Preorder Traversal (Root, Left, Right)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
    
    // Postorder Traversal (Left, Right, Root)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }

private:
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
    
    void preorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
    
    void postorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
};

// Helper function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

// Helper function to print traversal results
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution sol;
    
    cout << "Inorder Traversal: ";
    printVector(sol.inorderTraversal(root));
    
    cout << "Preorder Traversal: ";
    printVector(sol.preorderTraversal(root));
    
    cout << "Postorder Traversal: ";
    printVector(sol.postorderTraversal(root));
    
    return 0;
}
