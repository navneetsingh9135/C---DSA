#include<iostream>
using namespace std;
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int *ptr=arr;
    cout<<"\nArrange elements of Array";
    for(int i=0;i<10;i++){
        cout<<ptr<<endl;
    ptr++;
    }
    return 0;
}