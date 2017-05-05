//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/7/2.
//  Copyright (c) 2016年 wzcjj. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <functional>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 55
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int b[maxn];
vector<int> a[maxn];
double dp[maxn][maxn][maxn];
int n,k1,k2;
void dfs(int x,int fa){
    bool z=0;
        for(int i=k1;i<=k2;i++){
            dp[x][i][1]=1.0*b[x]/i;
        }
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa){
        z=1;
        dfs(a[x][i],x);
        double mi=100000000000LL;
        for(int j=k1;j<=k2;j++){
            mi=min(mi,dp[a[x][i]][j][j]);
        }
        for(int j=k1;j<=k2;j++){
            for(int k=j;k>=1;k--){
                double minn=dp[x][j][k]+mi;
                for(int l=1;l<k;l++){
                    minn=min(minn,dp[x][j][k-l]+dp[a[x][i]][j][l]);
                }
                dp[x][j][k]=minn;
            }
        }
    }
    if(z==0){
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,N;
    N=1;
    while (N--) {
        scanf("%d%d%d",&n,&k1,&k2);
        //memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        double sum=0;
        for(i=1;i<=n;i++)sum+=b[i];
        for(i=1;i<=n;i++){
            for(j=k1;j<=k2;j++){
                for(int k=0;k<=j;k++)dp[i][j][k]=sum*2;
            }
        }
        for(i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        dfs(1,-1);
        double ans=sum*2;
        /*for(i=1;i<=n;i++){
            for(j=k1;j<=k2;j++){
                for(int k=1;k<=j;k++)printf("%.2lf ",dp[i][j][k]);
                printf("\n");
            }
        }*/
        for(j=k1;j<=k2;j++)if(dp[1][j][j]<ans)ans=dp[1][j][j];
        printf("%.2lf\n",ans);
    }
    return 0;
}
