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
//isIdentical
bool isIdentical(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1==NULL|| root2==NULL){
        return false;
    }
    else{
        bool cond1=root1->data==root2->data;
        bool cond2=isIdentical(root1->left,root2->left);
        bool cond3=isIdentical(root1->right,root2->right);
        if(cond1 && cond2 && cond3){
            return true;
        }
        return false;
    }

}
int main(){
    node* root=new node(2);
    root->left=new node(1);
    root->right=new node(3);
    if(isIdentical(root,root)){
        cout<<"BSTs are identical"<<endl;
    }else{
        cout<<"BSTs are not identical"<<endl;
    }
    return 0;
}