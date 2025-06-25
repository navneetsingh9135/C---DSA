#include<iostream>
#include<vector>
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

vector<node*> constructBSTrees(int start, int end) {
    vector<node*> trees;
    if (start > end) {  
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++) {
        vector<node*> leftSubtrees = constructBSTrees(start, i - 1);
        vector<node*> rightSubtrees = constructBSTrees(i + 1, end);

        for (int j = 0; j < leftSubtrees.size(); j++) {
            node* left = leftSubtrees[j];
            for (int k = 0; k < rightSubtrees.size(); k++) {
                node* right = rightSubtrees[k];
                node* root = new node(i);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
        }
    }
    return trees;
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<node*> totalTrees = constructBSTrees(1, 3);
    for (int i = 0; i < totalTrees.size(); i++) {
        cout << (i + 1) << ": ";
        preorder(totalTrees[i]);
        cout << endl;
    }
    return 0;
}
