#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
long long a[105][105];
long long dp[105][105];
long long la[105][105];
long long b[105];
int main()
{
    int i,j,m,n,I,N,k;
    cin>>N;
    for(int I=1;I<=N;I++){
        cin>>n>>m;
        for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
        for(i=1;i<=n;i++)for(j=1;j<=m;j++)dp[i][j]=((long long)1<<62);
        for(i=1;i<=m;i++)dp[1][i]=a[1][i];
        /*for(i=1;i<=n;i++){
            for(j=1;j<=m;j++)cout<<a[i][j]<<' ';
            cout<<endl;
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++)cout<<dp[i][j]<<' ';
            cout<<endl;
        }*/
        for(i=2;i<=n;i++){
            for(j=1;j<=m;j++)for(k=j-1;k<=j+1;k++)if(k>0&&k<=m)if(dp[i-1][k]+a[i][j]<=dp[i][j]){
                dp[i][j]=dp[i-1][k]+a[i][j];
                la[i][j]=k;
            }
        }
        long long ans=((long long)1<<62);
        int t=0;
        for(i=1;i<=m;i++)if(dp[n][i]<=ans){
            ans=dp[n][i];
            t=i;
        }
        printf("Case %d\n",I);
        for(i=n;i>=1;i--){
            b[i]=t;
            t=la[i][t];
        }
        for(i=1;i<=n;i++){
            if(i<n)printf("%d ",b[i]);
            else printf("%d\n",b[i]);
        }
    }
    return 0;
}
