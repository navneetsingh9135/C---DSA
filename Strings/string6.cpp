#include<iostream>
#include<string>
using namespace std;
int main(){
    char s[20];
    int i;
    cout<<"\nEnter a string";
    gets(s);
    cout<<"\nstring=";
    for(i=0;s[i]!=0;i++)
    cout<<"\n"<<s[i];
    return 0;
}