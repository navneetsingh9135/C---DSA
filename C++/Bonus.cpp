#include<iostream>
using namespace std;
int main(){
    float amt;
    cout<<"\nEnter Income";
    cin>>amt;
    if(amt<2000)
    cout<<"\nBonus=Zero";
    else 
    if(amt<=5000)
    cout<<"\nBonus="<<amt*.10;
    else
    cout<<"\nBonus="<<500+amt*.05;
    return 0;
}