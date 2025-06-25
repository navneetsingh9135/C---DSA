#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"\nEnter a number";
    cin>>n;
    for(int i=n;i>=1;i--){
        for(int j=1;j<n;j++){
            cout<<" ";
        }
        for(int j=1;j<(2*i-1);j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            cout<<"\n";
        }
        for( int j=1;j<(2*i-1);j++){
            cout<<"*";
        }
        cout<<"\n";   }
}