# include <iostream.h>
class Node{
  int r,c,v;
  Node *next;
  friend Sparse;
};

class Sparse {
  Node *head,*list;
public:
  Sparse(){head=list=new Node;}
  void input();
  void display();
  void sum();
};
void Sparse::input(){
  for(;;){
   cout<<"\nEnter row '0 for end' ";cin>>list->r;
   if(list->r==0) {
    list->next=0;
    break;
   }
   cout<<"\nEnter col ";cin>>list->c;
   cout<<"\nEnter value ";cin>>list->v;
   list->next=new Node;
   list=list->next;
 }
}
void Sparse::sum(){
  Node *temp,*temp1;
  for(list=head;list->next!=0;list=list->next)
  for(temp1=list,temp=list->next;temp->next!=0;temp1=temp,temp=temp->next)
	if(list->r==temp->r&&list->c==temp->c)
	{
	list->v=list->v+temp->v;
	temp1->next=temp->next;
	delete temp;
	temp=temp1;
	}
}
void Sparse::display(){
  list=head;
  cout<<"\nRow\tCol.\tValue";
  while(list->next!=0){
   cout<<"\n"<<list->r<<"\t"<<list->c<<"\t"<<list->v;
   list=list->next;
  }
}
void main(){
   Sparse s;
   s.input();
   s.sum();
   s.display();
}