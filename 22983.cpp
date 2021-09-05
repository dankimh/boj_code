#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,i,j;
    cin>>n>>m;
    vector<string> a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<ll>> dp(n,vector<ll>(m,0));
    vector<vector<ll>> sq(n,vector<ll>(m,0));
    for(i=0;i<m;i++){dp[0][i]=i+1;sq[0][i]=1;}
    for(i=0;i<n;i++){dp[i][0]=i+1;sq[i][0]=1;}
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            if(a[i-1][j]!=a[i][j]&&a[i][j-1]!=a[i][j]&&a[i-1][j-1]==a[i][j]){
                sq[i][j]=min({sq[i-1][j],sq[i][j-1],sq[i-1][j-1]});
                sq[i][j]++;
            }
            else sq[i][j]=1;
            dp[i][j]+=sq[i][j];
        }
    }
    cout<<dp[n-1][m-1];
}
