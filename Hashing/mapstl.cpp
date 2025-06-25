#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int,greater<string>> directory;
    directory["naman"]=3876;
    directory["harsh"]=87700;
    directory["shubham"]=89797;
    for(auto element:directory){
        cout<<"Name-"<<element.first<<endl;
        cout<<"Phone number.-"<<element.second<<endl;
    }cout<<endl;
   // directory["shubham"]=87979;
    //for(auto element:directory){//
    //cout<<"Name-"<<element.first<<endl;
   // cout<<"Phone number.-"<<element.second<<endl;
   // }//
   map<string,int>::reverse_iterator itr;
   for(itr=directory.rbegin();itr!=directory.rend();itr++){
    cout<<itr->first<<"-"<<itr->second<<endl;
   }
    return 0;
}