#include<bits/stdc++.h>
#define INT_MAX (1<<27)
using namespace std;
int n,w;
int left(int x){
    if(x<n){
        return (x-1+n)%n;
    }
    else return (x-1+n)%n+n;
}
int right(int x){
    if(x<n){
        return (x+1)%n;
    }
    else return (x+1)%n+n;
}
int up(int x){return x+n;}
int down(int x){return x-n;}
vector<vector<int>> dp(10002,vector<int> (3,0));//0=ud, 1=u, 2=d
vector<int> cost;
void cal(){
    int i;
    for(i=2;i<=n;i++){
        //cout<<i<<"\n";
        int d=cost[i-1]+cost[left(i-1)]<=w?1:2;
        int u=cost[up(i-1)]+cost[left(up(i-1))]<=w?1:2;
        int v=cost[i-1]+cost[up(i-1)]<=w?1:2;
        //cout<<u<<" "<<d<<" "<<v<<"\n";
        dp[i][0]=min({dp[i-1][0]+v,dp[i-2][0]+u+d,dp[i-1][1]+d+1,dp[i-1][2]+u+1});
        dp[i][1]=min({dp[i-1][2]+u,dp[i-1][0]+1});
        dp[i][2]=min({dp[i-1][1]+d,dp[i-1][0]+1});
    }
}
void solve(){
    int i;
    cin>>n>>w;
    cost.clear();
    cost.resize(2*n);
    for(i=0;i<2*n;i++){
        cin>>cost[i];
    }
    dp[1][0]=cost[0]+cost[up(0)]<=w?1:2;
    dp[1][1]=dp[1][2]=1;
    cal();
    int ans=INT_MAX;
    ans=min(ans,dp[n][0]);
    //cout<<ans<<"x\n";
    if(cost[0]+cost[left(0)]<=w){
        int imsi=cost[0];
        dp[1][0]=2;
        dp[1][1]=dp[1][2]=1;
        cost[0]=INT_MAX;
        cal();
        ans=min(ans,dp[n][1]);//cout<<ans<<"y\n";
        cost[0]=imsi;
    }
    //cout<<up(0)<<"\n";
    if(cost[up(0)]+cost[left(up(0))]<=w){
        int x=up(0);
        int imsi=cost[x];
        dp[1][0]=2;
        dp[1][1]=dp[1][2]=1;
        cost[x]=INT_MAX;
        cal();
        ans=min(ans,dp[n][2]);
        cost[x]=imsi;//cout<<ans<<"z\n";
    }
    if(cost[0]+cost[left(0)]<=w&&cost[up(0)]+cost[left(up(0))]<=w){
        int imsi1=cost[0];
        int imsi2=cost[up(0)];
        dp[1][0]=2;
        dp[1][1]=dp[1][2]=1;
        cost[0]=cost[up(0)]=INT_MAX;
        cal();
        ans=min(ans,dp[n-1][0]);
        cost[0]=imsi1;
        cost[up(0)]=imsi2;
    }
    if(n==1){
        ans=cost[0]+cost[1]<=w?1:2;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)solve();
}
