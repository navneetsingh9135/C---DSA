#include<iostream>
#include<unordered_map>
#include<vector> 
#include<string> 
using namespace std;
int main(){
    unordered_map<int,string> record;
    //roll no,name
    record.insert(make_pair(3,"ria"));
    record[1]="bali";
    record[2]="animesh";
    record[3]="payal";
    for(auto pair:record){
        cout<<"Roll no-"<<pair.first<<endl;
        cout<<"Name-"<<pair.second<<endl; 
    }
}