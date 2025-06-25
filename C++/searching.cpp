#include<iostream>
using namespace std;
int search(int list[], int s)
{
    int pos;
    for(int i=0;i<=10;i++){
        cout<<s;
        if(list[i]==s)
        pos=i;
        break;
    }
    return pos;
}

int main(){
    int list[10],i,s,pos=-1;
    cout<<"\nEnter 10 numbers";
    for(i=0;i<10;i++)
    cin>>list[i];
    cout<<"\nEnter a number to search";
    cin>>s;
    
     pos=search(list,s);
    if(pos==-1)
    cout<<"\nNo is not Found";
    else
    cout<<"\nPositon="<<pos+1;
}

