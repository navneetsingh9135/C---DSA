#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setbits(x) __builtin_popcountll(x)
const int N=1e3+2;
int CoinChange(vi &a,int n,int x){
    if(x==0)
       return 1;
    if(x<0)
       return 0;
    if(n<=0)
       return 0;
    return CoinChange(a,n,x-a[n-1])+CoinChange(a,n-1,x);
}
signed main()
{
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
        int x;
    }
}