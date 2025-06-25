#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setbits(x) __builtin_popcountll(x)
signed main(){
    int n;
    cin>>n;
    vi a(n); 
    rep(i,0,n)
        cin>>a[i];
    int x;
    cin>>x;
    sort(a.begin(),a.end(),greater<int>());
    int ans=0;
    for(int i=n-1;i>=0;i--){
        if(x>=a[i]){
            ans+=x/a[i];
            x=x%a[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}