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
    return max(calcHeight(root->left),calcHeight(root->right)+1);
}
int calcDiameter(node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight= calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    int currDiameter=lHeight+rHeight+1;
    int lDiameter=calcDiameter(root->left);
    int rDiameter=calcDiameter(root->right);
    return max(currDiameter,max(lDiameter,rDiameter));
}
int main(){
    node* root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    //Diameter of Binary Tree
    cout<<calcDiameter(root)<<"\n";
    return 0;
}