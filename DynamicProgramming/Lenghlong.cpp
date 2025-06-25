#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second
#define setbits(x) __builtin_popcountll(x)
const int N=1e5+2, MOD=1e9+7;
int dp[N];
signed main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n)
        cin>>a[i];
    vi dp(n,1);
    int ans=0;
    rep(i,1,n){
        rep(j,0,i){
            if(a[i]>a[j])
                dp[i]=max(dp[i],1+dp[j]);

        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}