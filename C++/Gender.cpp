#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    char n[30],s;
    cout<<"\nEnter Name";
    gets(n);
    cout<<"\nEnter Gender";
    cin>>s;
    if(s=='m'||s=='M')
    cout<<"\nHello Mr"<<n;
    else if(s=='f'||s=='F')
    cout<<"\nHello Miss"<<n;
    else
    cout<<"\nInvalid Gender";
    return 0;
}