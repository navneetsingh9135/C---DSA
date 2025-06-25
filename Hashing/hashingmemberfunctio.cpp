#include<iostream>
#include<map>
using namespace std;
int main(){
    int array[]={1,1,1,1,1,2,3,3};
    map<int,int> m;
    for(int i=0;i<8;i++){
        m[array[i]]++;
    }
    for(auto i:m)
    cout<<"i.first"<<" - "<<i.second<<endl;
    int sum=0;
    for(auto i:m){
        sum+=(i.second-1);
    }
    cout<<sum<<endl;
}