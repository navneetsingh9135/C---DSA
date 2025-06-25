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
node* searchInBST(node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root; 
    }
    //data>key
    if(root->data>key){
        return searchInBST(root->left,key);
    }
    //data<key
        return searchInBST(root->right,key);
}
int main(){
    node* root=new node(4);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);
    if(searchInBST(root,5)==NULL){
        cout<<"Key doesn't exist";
    }else{
        cout<<"Key exists";
    }
    return 0;
}