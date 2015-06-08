#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
struct node{
    int x[5],y[5];
    int sum;
}dp[5005][50];
int x[5],y[5],z[5],now,last;
void swap(int &x,int &y){
    int t=x;
    x=y;
    y=t;
}
void dfs(int step,int t){
    if(t==5){
        for(int i=2;i<=4;i++)if(dp[step][now].y[i]<dp[step][now].y[i-1])return;
        dp[step][now].sum=2000000000;
        for(int i=0;i<=last;i++){
            int sum=dp[step-1][i].sum;
            for(int j=1;j<=4;j++)sum+=abs(dp[step][now].x[j]-dp[step-1][i].x[j])+abs(dp[step][now].y[j]-dp[step-1][i].y[j]);
            if(sum<dp[step][now].sum)dp[step][now].sum=sum;
        }
        now++;
        dp[step][now]=dp[step][now-1];
        return;
    }
    for(int i=1;i<=4;i++)if(!z[i]){
        dp[step][now].x[t]=x[i];
        dp[step][now].y[t]=y[i];
        z[i]=1;
        dfs(step,t+1);
        z[i]=0;
    }
}
int main(){
    int i,j,m,n,N,k,l;
    cin>>N;
    int I=0;
    while(N--){
        I++;
        printf("Case #%d:\n",I);
        cin>>n;
        dp[0][0].x[1]=dp[0][0].x[2]=dp[0][0].x[3]=dp[0][0].x[4]=0;
        for(i=1;i<=4;i++)dp[0][0].y[i]=i;
        dp[0][0].sum=0;
        last=0;
        for(i=1;i<=n;i++){
            scanf("%d%d%d%d%d%d%d%d",&x[1],&y[1],&x[2],&y[2],&x[3],&y[3],&x[4],&y[4]);
            memset(z,0,sizeof(z));
            now=0;
            dfs(i,1);
            last=now-1;
        }
        int ans=2000000000;
        for(i=0;i<now;i++)if(ans>dp[n][i].sum)ans=dp[n][i].sum;
        printf("%d\n",ans);
    }
    return 0;
}
