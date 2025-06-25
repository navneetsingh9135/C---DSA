#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int val){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=val;
    node->left=NULL;
    node->right=NULL;
}
calc