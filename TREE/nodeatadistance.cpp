#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// Case 1: Print all nodes at distance k in the subtree rooted with root
void printSubtreenodes(node* root, int k){
    if(root == NULL || k < 0){
        return;
    }
    if(k == 0){
        cout << root->data << " ";
        return;
    }
    printSubtreenodes(root->left, k - 1);
    printSubtreenodes(root->right, k - 1);
}

// Case 2: Find the distance of target from root and print nodes at distance k
int printnodesAtk(node* root, node* target, int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        printSubtreenodes(root, k);
        return 0;
    }

    // Search for target in left subtree
    int dl = printnodesAtk(root->left, target, k);
    if(dl != -1){
        if(dl + 1 == k){
            cout << root->data << " ";
        } else {
            printSubtreenodes(root->right, k - dl - 2);
        }
        return dl + 1;
    }

    // Search for target in right subtree
    int dr = printnodesAtk(root->right, target, k);
    if(dr != -1){
        if(dr + 1 == k){
            cout << root->data << " ";
        } else {
            printSubtreenodes(root->left, k - dr - 2 );
        }
        return dr + 1;
    }
    
    return -1;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    
    // Test the function
    printnodesAtk(root, root->left, 1);

    return 0;
}
