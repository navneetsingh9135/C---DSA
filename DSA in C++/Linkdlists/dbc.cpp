//Operation on doubly circular linked list

# include <iostream.h>
# include <conio.h>
# include <stdio.h>
class Node{
  int n;
  Node *pre,*next;
  friend DBCList;
};

class DBCList {
  Node *head,*list;
public:
  DBCList(){head=list=new Node;}
  void input();
  void display();
  void insert();
  void del();
};
void DBCList::input(){
  Node *temp;
  for(;;){
   cout<<"\nEnter a no. '0 for end' ";cin>>list->n;
   if(list->n==0) {
    list->next=head;
    head->pre=list;
    break;
   }
   list->next=new Node;
   temp=list;
   list=list->next;
   list->pre=temp;
 }
}
void DBCList::display(){
  int no;
  list=head;
  cout<<"\nEnter a no to start ";
  cin>>no;
  while(list->next!=head){
	if(list->n==no)
	 break;
	list=list->next;
  }
  cout<<"\nDisplaying nos.";
  cout<<"\n"<<list->n;
  list=list->next;
  while(list->n!=no){
   cout<<"\n"<<list->n;
   list=list->next;
  }
  cout<<"\nDisplaying nos. in reverse order";
  cout<<"\n"<<list->n;
  list=list->pre;
  while(list->n!=no){
   cout<<"\n"<<list->n;
   list=list->pre;
  }
   cout<<"\n"<<list->n;
}
void DBCList::insert(){
  Node *temp;
  int key;
  list=head;
  temp=new Node;
  cout<<"Value of new item ?";
  cin>>temp->n;
  cout<<"Value of key item ? (type 0 if last) ";
  cin>>key;
  if(head->n==key) {
	 temp->next=head;
	 temp->pre=head->pre;
	 head->pre->next=temp;
	 head->pre=temp;
	 head=temp;
  }
  else {
	 while(list->next->next!=0)
		if(list->next->n==key)
		  break;
		else
		  list=list->next;
	 temp->next=list->next;
	 list->next=temp;
	 temp->next->pre=temp;
	 temp->pre=list;
  }
}

void DBCList::del(){
  Node *temp;
  int key;
  list=head;
  cout<<"Value to delete ?";
  cin>>key;
  if(head->n==key) {
	 head->next->pre=head->pre;
	 head->pre->next=list->next;
	 head=list->next;
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
	 temp->next->pre=list;
	 delete temp;
  }
}
void main(){
  int choice;
  DBCList l;
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