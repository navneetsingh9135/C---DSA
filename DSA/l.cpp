 # include <iostream>
using namespace std;
class Node{
  int n;
  Node *next;
  friend class Linkedlist;
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
int main(){
  Linkedlist l;
  l.input();
  l.display();
  return 0;
}