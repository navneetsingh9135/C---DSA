#include<iostream>
using namespace std;
int main(){
    int arr[10],i;
    cout<<"\nEnter 10 numbers";
    for(i=0;i<10;i++)
    cin>>arr[i];
    cout<<"\nDisplaying the number";
    for(i=0;i<10;i++){
        cout<<"\n"<<arr[i];
    }
}