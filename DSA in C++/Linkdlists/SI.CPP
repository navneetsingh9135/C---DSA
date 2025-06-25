//Operation on linked list

# include <iostream.h>
# include <conio.h>
# include <stdio.h>
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
  void insert();
  void del();
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
void Linkedlist::insert(){
  Node *temp;
  int key;
  list=head;
  temp=new Node;
  cout<<"Value of new item ?";
  cin>>temp->n;
  cout<<"Value of key item ? (type 0 if last) ";
  cin>>key;
  if(head->n==key) {
	 temp->next=head; head=temp;
  }
  else {
	 while(list->next->next!=0)
		if(list->next->n==key)
		  break;
		else
		  list=list->next;
	 temp->next=list->next;
	 list->next=temp;
  }
}

void Linkedlist::del(){
  Node *temp;
  int key;
  list=head;
  cout<<"Value to delete ?";
  cin>>key;
  if(head->n==key) {
	 head=head->next;
	 delete list;
  }
  else {
  while(list->next->next!=0)
	 if(list->next->n==key)
		break;
	 else
		list=list->next;
	 temp=list->next;
	 list->next=temp->next;
	 delete temp;
  }
}
void main(){
  int choice;
  Linkedlist l;
  do {
	clrscr();
	cout<<"\n\tM E N U";
	cout<<"\n1. Creating a linked list";
	cout<<"\n2. Display the list ";
	cout<<"\n3. Inserting item to the list ";
	cout<<"\n4. Deleting an item ";
	cout<<"\n5. Exit";
	cout<<"\n   Select your choice :";
	cin>>choice;
	if(choice==1) l.input();
	if(choice==2) {l.display();getch();}
	if(choice==3) l.insert();
	if(choice==4) l.del();
  }while(choice!=5);
}