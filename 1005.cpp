#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k,i;
    cin>>n>>k;
    vector<int> cost(n+1);
    vector<int> tot(n+1,-1);
    vector<int> vis(n+1,0);
    vector<int> dp(n+1,0);
    vector<int> top(n+1,0);
    vector<vector<int>> mp(n+1);
    for(i=1;i<=n;i++){
        cin>>cost[i];
        dp[i]=cost[i];
    }
    for(i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        top[y]++;
    }
    queue<int> s;
    vector<int> l;
    for(i=1;i<=n;i++){
        if(top[i]==0){s.push(i);}
    }
    while(!s.empty()){
        int now=s.front();
        l.push_back(now);
        s.pop();
        for(auto &i:mp[now]){
            top[i]--;
            if(top[i]==0)s.push(i);
            if(dp[i]<dp[now]+cost[i])dp[i]=dp[now]+cost[i];
        }
    }
    int w;
    cin>>w;
    cout<<dp[w]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)solve();
}
