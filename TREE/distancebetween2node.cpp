#include<iostream>
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

// Function to find the Lowest Common Ancestor (LCA)
node* LCA(node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == n1 || root->data == n2) {
        return root;
    }

    node* left = LCA(root->left, n1, n2);
    node* right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL) {
        return root;
    }
    if (left != NULL) {
        return left;
    }
    return right;
}

// Function to find distance from root to a given key `k`
int findDist(node* root, int k, int dist) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == k) {
        return dist;
    }

    int left = findDist(root->left, k, dist + 1);
    if (left != -1) {
        return left;
    }
    return findDist(root->right, k, dist + 1);
}

// Function to find the distance between two nodes
int distBtwnodes(node* root, int n1, int n2) {
    node* lca = LCA(root, n1, n2);
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    return d1 + d2;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);                                                          
    root->left->left = new node(4);
    root->right->right = new node(5);

    // Test: Calculate distance between nodes 4 and 5
    cout << distBtwnodes(root, 4, 5) << endl;  // Corrected: passing two node values

    return 0;
}
