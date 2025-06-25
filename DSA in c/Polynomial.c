#include<stdio.h>
#include<stdlib.h>
struct Polynomial{
    int coeff;
    int exp;
    struct Polynomial *next;
};
typedef struct Polynomial node;

void display(node *head)
{
    if(head==NULL)
            return;
    printf("%dx^%d",head->coeff,head->exp);
    display(head->next);
}

void insert(node **head,int coeff,int exp)
{
    node *n=(node*)malloc(sizeof(node));
    n->coeff=coeff;
    n->exp=exp;
    n->next=*head;
    *head=n;
}

node *add(node *head1,node *head2)
{
    node *head3=NULL;
    node **lastPtrRef=&head3;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->exp>head2->exp)
        {
            *lastPtrRef=head1;
            head1=head1->next;
        }
        else if(head1->exp<head2->exp)
        {
            *lastPtrRef=head2;
            head2=head2->next;
        }
        else
        {
            *lastPtrRef=head1;
            head1=head1->next;
            head2=head2->next;
        }
        lastPtrRef=&((*lastPtrRef)->next);
}

node *sub(node *head1,node *head2)
{

}

node *mul(node *head1,node *head2)
{

}

node *div(node *head1,node *head2)
{

}

node *mod(node *head1,node *head2)
{

}

node *pow(node *head1,node *head2)
{

}

node *root(node *head1,node *head2)
{

}


int main()
{

}

