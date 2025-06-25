# include <iostream.h>
# include <stdio.h>
# include <string.h>
class Node{
  char n[20];
  Node *next;
  friend Linkedlist;
};

class Linkedlist {
  Node *head,*list;
public:
  Linkedlist(){head=list=new Node;}
  void input();
  void display();
};
void Linkedlist::input(){
  for(;;){
   cout<<"\nEnter a string 'Input stop for end' ";gets(list->n);
   if(strcmp(list->n,"stop")==0) {
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
void main(){
  Linkedlist l;
  l.input();
  l.display();
}