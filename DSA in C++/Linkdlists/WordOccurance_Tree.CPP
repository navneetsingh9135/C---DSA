# include <fstream.h>
# include <string.h>
class Node{
  char word[20];
  int c;
  Node *next;
  friend Linkedlist;
};

class Linkedlist {
  Node *head,*list;
  void mainJob(char[]);
public:
  Linkedlist(){head=list=new Node;list->next=0;}
  void input();
  void display();
};

void Linkedlist::mainJob(char word[]){

  if(flag==0){
   head = new Node;
   head->n=x;head->left=0;head->right=0;flag=1;
  }
  else {
   list=head;
   for(;;) {
    if(x<list->n)
     if(list->left==0) {
      list->left=new Node;
      list=list->left;
      list->n=x;
      list->left=0;
      list->right=0;
      break;
     }
     else
      list=list->left;
    else
     if(list->right==0) {
      list->right=new Node;
      list=list->right;
      list->n=x;
      list->left=0;
      list->right=0;
      break;
     }
     else
      list=list->right;
   }
  }
 }

      list=head;
      while(list->next!=0){
	if(strcmp(list->word,word)==0){
	  list->c++;
	  break;
	}
	list=list->next;
      }
      if(list->next==0){
	strcpy(list->word,word);
	list->c=1;
	list->next=new Node;
	list=list->next;
	list->next=0;
      }
}

void Linkedlist::input(){
  char word[20];
  char ch;
  int i=0;
  fstream file;
  file.open("aa.txt",ios::in);
  ch=file.get();
  while(!file.eof()){
    if(ch==' '){
      word[i]='\0';
      mainJob(word);
      ch=file.get();
      i=0;
    }
    word[i++]=ch;
    ch=file.get();
  }
  file.close();
  word[i]='\0';
  mainJob(word);
}

void Linkedlist::display(){
  cout<<"\nWord\t\tOccurance";
  list=head;
  while(list->next!=0){
   cout<<"\n"<<list->word<<"\t\t"<<list->c;
   list=list->next;
  }
}

void main(){
  Linkedlist l;
  l.input();
  l.display();
}