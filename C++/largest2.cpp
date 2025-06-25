#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"\nEnter the value of a";
    cin>>a;
    cout<<"\nEnter the value of b";
    cin>>b;
    cout<<"\nEnter the value of c";
    cin>>c;
    if(a>b&&a>c)
    cout<<"\nValue of a is Largest";
    else if (b>a&&b>c)
    cout<<"\nValue of b is Largest";
    else
    cout<<"\nValue of c is Largest";
    return 0;
    
}
