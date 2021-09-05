#include<bits/stdc++.h>
using namespace std;
int fx(int a){
    return a<0?-a:a;
}
void solve(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    double dist=sqrt((a-d)*(a-d)+(b-e)*(b-e));
    double sum=(double)(c+f),sub=(double)(fx(c-f));
    if(sum<dist)cout<<"0\n";
    else if(sum==dist)cout<<"1\n";
    else{
        if(sub<dist)cout<<"2\n";
        else if(sub==dist){
            if(a==d&&b==e)cout<<"-1\n";
            else cout<<"1\n";
        }
        else cout<<"0\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
