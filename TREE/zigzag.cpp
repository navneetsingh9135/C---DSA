#include <iostream>
#include<stack>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void zigzagTraversal(node *root)
{
    if(root==NULL){
        return;
    }
    stack<node *> currLevel;
    stack<node *> nextLevel;
    bool leftToRight = true;
    currLevel.push(root);
    while (!currLevel.empty())
    {
        node *temp = currLevel.top();
        currLevel.pop();
        if (temp)
        {
            cout << temp->data << " ";

            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            // Right to Left
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        if(currLevel.empty()){
            leftToRight=!leftToRight;
            swap(currLevel,nextLevel);
        }
    }
}
int main(){
    node* root=new node(12);
    root->left=new node(9);
    root->right=new node(15);
    root->left->left=new node(5);
    root->left->right=new node(10);
    //test
    zigzagTraversal(root);
    cout<<endl;
    return 0;
}