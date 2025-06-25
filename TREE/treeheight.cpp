#include<bits/stdc++.h>
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
int calcHeight(node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight=calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    return max(lHeight,rHeight)+1;
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    //Height of Binary Tree
    cout<<calcHeight(root)<<"\n";
    return 0;
}