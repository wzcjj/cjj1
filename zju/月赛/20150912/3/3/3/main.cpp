#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=205;

int dp[maxn][maxn][2];
int dp1[maxn][maxn];
char w[maxn];
int tr[maxn];
int dfs(int i,int j,int k)
{
    if (dp[i][j][k]!=-1) return dp[i][j][k];
    else
    {
        dp[i][j][k]=0;
        if (j-i<=3) {
            //	if (j==i && tr[i]==k) dp[i][j][k]=1;
            if (j-i==2 && tr[i+1]==k) dp[i][j][k]=1;
            return dp[i][j][k];
        }
        for (int i1=i+1;i1<j;i1++)
        {
            if (tr[i1]==k)
            {
                for (int i2=0;i2<2;i2++)
                    if (dfs(i,i1,i2) && dfs(i1,j,i2))
                    {
                        dp[i][j][k]=1;
                        return dp[i][j][k];
                    }
            }
        }
    }
    return dp[i][j][k];
}

int dfs2(int i,int j)
{
    if (dp1[i][j]!=-1) return dp1[i][j];
    if (j-i<=3)
    {
        dp1[i][j]=0;
        return dp1[i][j];
    }
    dp1[i][j]=0;
    
    //int v=0;
    if (dfs(i,j,0) || dfs(i,j,1)) dp1[i][j]=j-i-2;
    else
        for (int i1=i+1;i1<j;i1++)
        {
            //if (dfs2(i,i1)+dfs2(i1,j)>dp1[i][j]) v=i1;
            dp1[i][j]=max(dp1[i][j],dfs2(i,i1)+dfs2(i1,j));
        }
    //printf("--%d %d %d\n",i,j,v);
    return dp1[i][j];
}

int main()
{
    int t,k,n;
    scanf("%d",&t);
    for (int I=0;I<t;I++)
    {
        scanf("%d",&n);
        scanf("%s",w);
        for (int i=1;i<=n;i++)
        {
            if (w[i-1]=='B') tr[i]=1;
            else tr[i]=0; 
        }
        for (int i=0;i<=n+1;i++)
        {
            for (int j=0;j<=n+1;j++)
            {
                dp1[i][j]=-1;
                for (int k=0;k<2;k++)
                    dp[i][j][k]=-1;
            }
        }
        
        printf("%d\n",dfs2(0,n+1));
    }
    return 0;
}