#include"bits/stdc++.h"
using namespace std;
//function overloading
class Apnacollege{
    public:
    void fun(){
        cout<<"\nI am a function with no arguments"<<endl;
    }
    void fun(int x){
        cout<<"\nI am a function with int arguments"<<endl;
    }
    void fun(double x){
        cout<<"\nI am a function with double arguments"<<endl;
    }
};
int32_t main(){
    Apnacollege obj;
    obj.fun();
    obj.fun(4);
    obj.fun(6.2);
}