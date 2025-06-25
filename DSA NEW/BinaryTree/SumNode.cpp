#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int sumTree(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    root->data += leftSum + rightSum;
    return root->data;
}

int main() {
    // Example tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Pre-order before sumTree: ";
    preOrder(root);
    cout << endl;

    sumTree(root);

    cout << "Pre-order after sumTree: ";
    preOrder(root);
    cout << endl;

    return 0;
}
