#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    //convert into upper case.
    string str="navneetsingh";
    for(int i=0;i<str.size();i++){
        if(str[i]>='a'&&str[i]<='z')
           str[i]-=32;
        }
        cout<<str<<endl;
        return 0;
}