#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setbits(x) __builtin_popcountll(x)
int fib(int n){
    if(n==0)    
      return 0;
    if(n==1)
      return 0;
    if(n==2)
      return 1;
    return fib(n-1)+fib(n-2);
}
signed main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
}