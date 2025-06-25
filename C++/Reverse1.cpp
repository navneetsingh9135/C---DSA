#include<iostream>
using namespace std;
int main(){
    int n,remainder,rev=0;
    cout<<"\nEnter a number";
    cin>>n;
    while(n!=0){
        remainder=n%10;
        rev=rev*10+remainder;
        n=n/10;
    }
    cout<<rev;
}