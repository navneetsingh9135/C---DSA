#include<iostream>
using namespace std;
int main(){
    int list[10],i,l,t;
    cout<<"\nEnter 10 numbers";
    for(i=0;i<10;i++)
    cin>>list[i];
    for(i=0;i<9;i++)
    for(l=0;l<9-i;l++)
    if(list[l+1]<list[l]){
        t=list[l];
        list[l]=list[l+1];
        list[l+1]=t;
    }
    cout<<"\nDisplaying the arranged numbers";
    for(i=0;i<10;i++)
    cout<<list[i]<<" ";
}