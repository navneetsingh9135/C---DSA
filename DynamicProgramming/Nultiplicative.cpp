#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+2,MOD=1e9+7;

struct triplet{
    int x,y,gcd;
};
triplet extendedEuclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.gcd=a;
        ans.y=0;
        return ans;
    }
    triplet smallAns=extendedEuclid(b,a%b);
    triplet ans;
    ans.x=smallAns.y;
    ans.gcd=smallAns.gcd;   
    ans.y=smallAns.x-(a/b)*smallAns.y;
    return ans;
}
int multiplicativeModuleInverse(int a,int m){
    triplet temp=extendedEuclid(a,m);
    return temp.x;
}
signed main(){
    int a,m;
    cin>>a>>m;
    cout<<multiplicativeModuleInverse(a,m)<<endl;
    return 0;
}