#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
