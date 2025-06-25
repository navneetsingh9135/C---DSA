#include<iostream>
using namespace std;
bool ispowerof3(int n){
    return (n&&(!n&n-1));
}
int main(){
    cout<<ispowerof3(9)<<endl;
    return 0;
}