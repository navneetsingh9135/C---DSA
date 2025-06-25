#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrder(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* currNode = q.front();
        q.pop();

        if (currNode != NULL) {
            cout << currNode->data << " ";
            
            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);
        } 
        else if (!q.empty()) {
            q.push(NULL);
        }   
    }
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    printLevelOrder(root);
    return 0;
}
