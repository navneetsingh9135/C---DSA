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
  void split();
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
void Linkedlist::split(){
  Linkedlist a,b;
  list=head;
  while(list->next!=0){
    if(list->n%2==0){
       a.list->n=list->n;
       a.list->next=new Node;
       a.list=a.list->next;
   }
  else{
       b.list->n=list->n;
       b.list->next=new Node;
       b.list=b.list->next;
   }
  list=list->next;
 }
 a.list->next=0;
 b.list->next=0;
 cout<<"\nDisplaying original list ";display();
 cout<<"\nDisplaying first list ";a.display();
 cout<<"\nDisplaying second list ";b.display();
}
void main(){
  Linkedlist l;
  l.input();
  l.split();
}