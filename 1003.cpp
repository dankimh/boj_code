#include<bits/stdc++.h>
int m[40];
int f(int n){
    if(m[n])return m[n];
    if(n==0)return m[0]=0;
    else if(n==1)return m[1]=1;
    else return m[n]=f(n-1)+f(n-2);
}
int main(){
    int n,i,a;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        if(a>1)printf("%d %d\n",f(a-1),f(a));
        else if(a==1)printf("0 1\n");
        else if(a==0)printf("1 0\n");
    }
}
