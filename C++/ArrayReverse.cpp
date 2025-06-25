#include<iostream>
using namespace std;
int main(){
    int arr[5],i;
    cout<<"\nEnter 5 numbers";
    for(i=1;i<=5;i++)
    cin>>arr[i];
    cout<<"\nDisplaying the numbers";
    for(i=5;i>=1;i--){
        cout<<arr[i];
    }
}