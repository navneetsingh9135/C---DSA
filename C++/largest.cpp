#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"\nEnter the 1st Number";
    cin>>a;
    cout<<"\nEnter the 2nd Number";
    cin>>b;
    if(a==b)
    cout<<"\nBoth are Equal";
    else if(a>b)
    cout<<"\nFirst Number is Larger";
    else
    cout<<"\nSecond Number is Larger";
    return 0;
}