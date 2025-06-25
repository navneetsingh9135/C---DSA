#include<bits/stdc++.h>
using namespace std;

// Definition of the node structure
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

// Function to search for a value in the inorder array
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) {
            return i;
        }
    }
    return -1;
}

// Function to build the tree from postorder and inorder traversals
node* buildTree(int postorder[], int inorder[], int start, int end, int& idx) {
    if (start > end) {
        return NULL;
    }
    
    int val = postorder[idx];
    idx--;
    node* curr = new node(val);

    // If it's a leaf node, return the node
    if (start == end) {
        return curr;
    }

    // Search for the current node's value in the inorder array
    int pos = search(inorder, start, end, val);

    // Recursively build the right and left subtrees
    curr->right = buildTree(postorder, inorder, pos + 1, end, idx);
    curr->left = buildTree(postorder, inorder, start, pos - 1, idx);

    return curr;
}

// Function to print the tree in inorder traversal
void inorderPrint(node* root) {
    if (root == NULL) {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    // Define the postorder and inorder traversals
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    // Initialize the index for the postorder array
    int idx = 4;

    // Build the tree
    node* root = buildTree(postorder, inorder, 0, 4, idx);

    // Print the inorder traversal of the tree
    inorderPrint(root);
    cout << "\n";
    
    return 0;
}
