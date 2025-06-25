//From the biggest number from the numeric string//
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s="4794729372";
    sort(s.begin(),s.end(),greater<int>());
    cout<<s<<endl;
    return 0;
}