#include <iostream>
#include <vector>
#include<queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
static int idx = -1;

Node *buildTree(vector<int> preorder)
{
    idx++;
    if (preorder[idx] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);  // LEFT
    root->right = buildTree(preorder); // RIGHT
    return root;
}
void preOrder(Node *root)
{
    if(root==NULL){
        return;
    }
    cout<<root->data<<"  ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(Node *root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
// Levelorder
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHt=height(root->left);
    int rightHt=height(root->right);
    return max(leftHt,rightHt)+1;
}
int count(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftCount=count(root->left);
    int rightCount=count(root->right);
    return leftCount+rightCount+1;
}
int Sum(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum=Sum(root->left);
    int rightSum=Sum(root->right);
    return leftSum+rightSum+root->data;
}
int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    preOrder(root);//1 2 3 4 5
    inOrder(root);//2 1 4 3 5   
    postOrder(root);//2 4 3 5 1 
    levelOrder(root);//1 2 3 4 5
    cout<<"height:"<<height(root)<<endl;
    cout<<"count:"<<count(root)<<endl;
    cout<<"Sum:"<<Sum(root)<<endl;
    cout<<endl;
    return 0;
}