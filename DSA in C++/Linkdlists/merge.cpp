# include <iostream.h>
class Node{
  int n;
  Node *next;
  friend Linkedlist;
};

class Linkedlist {
  Node *head,*list;
public:
  Linkedlist(){head=list=new Node;}
  void input();
  void display();
  void merge(Linkedlist,Linkedlist);
};
void Linkedlist::input(){
  for(;;){
   cout<<"\nEnter a no. '0 for end' ";cin>>list->n;
   if(list->n==0) {
    list->next=0;
    break;
   }
   list->next=new Node;
   list=list->next;
 }
}
void Linkedlist::display(){
  list=head;
  while(list->next!=0){
   cout<<"\n"<<list->n;
   list=list->next;
  }
}
void Linkedlist::merge(Linkedlist a,Linkedlist b){
  a.list=a.head;  b.list=b.head;
  while(a.list->next!=0 && b.list->next!=0){
    if(a.list->n>b.list->n){
       list->n=b.list->n;
       b.list=b.list->next;
   }
  else{
       list->n=a.list->n;
       a.list=a.list->next;
   }
   list->next=new Node;
   list=list->next;
 }
 if(a.list->next==0)
     while(b.list->next!=0){
       list->n=b.list->n;
       b.list=b.list->next;
      list->next=new Node;
      list=list->next;
    }
 else
     while(a.list->next!=0){
       list->n=a.list->n;
       a.list=a.list->next;
      list->next=new Node;
      list=list->next;
    }
 list->next=0;
}
void main(){
  Linkedlist a,b,c;
  a.input();b.input();
  c.merge(a,b);
  c.display();
}