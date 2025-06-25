#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"\nEnter the 1st Number";
    cin>>a;
    cout<<"\nEnter the 2nd number";
    cin>>b;
    cout<<"\nEnter the 3rd Number";
    cin>>c;
    if(a==b &&a==c)
    cout<<"\nAll the three numbers are equal";
    else if(a>b&&a>c)
    cout<<"\nFirst Number is larger";
    else if(b>a&&b>c)
    cout<<"\nSecond Number is Larger";
    else
    cout<<"\nThird Number is Larger";
    return 0;
}