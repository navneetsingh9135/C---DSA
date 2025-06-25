#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data = val;
        left = NULL; 
        right = NULL; 
    }
};

int sumAtK(node* root, int K) { 
    if (root == NULL) {
        return -1;
    }

    queue<node*> q; 
    q.push(root); 
    q.push(NULL);

    int level = 0;
    int sum = 0;

    while (!q.empty()) {
        node* currNode = q.front(); 
        q.pop();

        if (currNode != NULL) {
            if (level == K) {
                sum += currNode->data;
            }
            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);
        }
        else if (!q.empty()) {
            q.push(NULL);
            level++;
        }
    }

    return sum;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5); 
    root->right->left = new node(6);
    root->right->right = new node(7);

    // Sum at Kth Level
    cout << sumAtK(root, 2);


    return 0;
}
