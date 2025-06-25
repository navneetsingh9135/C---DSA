//sorted list

# include <iostream.h>
# include <conio.h>
class Node{
  int n;
  Node *next;
  friend Linkedlist;
};

class Linkedlist {
  Node *head,*list;
public:
  Linkedlist(){head=list=new Node;head->next=0;}
  void input();
  void display();
};
void Linkedlist::input(){
  Node *temp;
  for(;;){
   temp=new Node;
   cout<<"\nEnter a no. '0 for end' ";
   cin>>temp->n;
   if(temp->n==0)
    break;
   if(head->next==0 || head->n>temp->n) {
	 temp->next=head; head=temp;
   }
   else {     list=head;
	 while(list->next->next!=0)
		if(list->next->n>temp->n)
		  break;
		else
		  list=list->next;
	 temp->next=list->next;
	 list->next=temp;
   }
   clrscr();
   display();
  }
}
void Linkedlist::display(){
  list=head;
  cout<<"\n";
  while(list->next!=0){
   cout<<"  "<<list->n;
   list=list->next;
  }
}

void main(){
  Linkedlist l;
  l.input();
}