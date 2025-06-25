#include<iostream>
#include<climits>
using namespace std;
int smallestSubarrayWithSum(int arr[],int n,int x){
    int sum=0;
    int minLength=n+1;
    int start=0;
    int end=0;
    while(end<n){
        while(sum<=x && end<n){
            sum+=arr[end++];
        }
        while(sum>x && sum<n){
            if(end-start<minLength){
                minLength=end-start;
            }
            sum-=arr[start++];
        }
    }
    return minLength;
}
int main(){
    int arr[]={1,4,45,6,10,19};
    int x=51;
    int n=6;
    int minLength=smallestSubarrayWithSum(arr,n,x);
    if(minLength==n+1){
        cout<<"no such subarray exists"<<endl;
    }else{
        cout<<"smallest length subarray is :"<<minLength<<endl;
    }
    return 0;
}