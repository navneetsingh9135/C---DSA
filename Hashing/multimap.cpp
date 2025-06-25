#include<iostream>
#include<map>
using namespace std;
int main(){
    multimap<string,int> directory;
    directory.insert(make_pair("aman",843738));
    directory.insert(make_pair("harsh",879797));
    directory.insert(make_pair("harsh",900000));
    for(auto pair:directory){
        cout<<"Name-"<<pair.first<<endl;
        cout<<"Roll no-"<<pair.second<<endl;
    }
    return 0;
}