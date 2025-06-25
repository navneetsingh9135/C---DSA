#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL:
    }
};
int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right)+1;

}
int main(){
    Node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    return 0;

}