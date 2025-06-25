#include<iostream>
#include<climits>
#include<algorithm> // for min, max
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
    node(int val) {
        data = val;
        left = NULL; 
        right = NULL;
    }
};

struct Info {
    int size;  // Size of subtree
    int max;   // Max value in subtree
    int min;   // Min value in subtree
    int ans;   // Size of largest BST
    bool isBST; // Is the subtree a BST
};

Info largestBSTinBT(node* root) {
    if (root == NULL) {
        return {0, INT_MIN, INT_MAX, 0, true};      
    }

    if (root->left == NULL && root->right == NULL) {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    // If the current subtree is a BST
    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data) {
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(rightInfo.max, max(leftInfo.max, root->data));
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }

    // If not a BST, return the size of the largest BST so far
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}

int main() {
    node* root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    cout << "Largest BST in BT: " << largestBSTinBT(root).ans << endl;
    return 0;
}
