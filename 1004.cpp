#include<bits/stdc++.h>
using namespace std;
int f(int a,int b,int c,int d,int r){
    return ((a-b)*(a-b)+(c-d)*(c-d)-r*r)<0?-1:1;
}
void solve(){
    int a,b,c,d,e,i,ans=0;
    cin>>a>>b>>c>>d>>e;
    for(i=0;i<e;i++){
        int p,q,r;
        cin>>p>>q>>r;
        if(f(a,p,b,q,r)*f(c,p,d,q,r)<0)ans++;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
