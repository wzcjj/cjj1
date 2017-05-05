//
//  main.cpp
//  8
//
//  Created by wzcjj on 16/8/9.
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
#define maxn 25
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int bc[1<<20],tmp[1<<20],sum[1<<20];
long long dp[maxn][maxn],fact[maxn],c[maxn][maxn];
long long gcd(long long x,long long y){
    if(y==0)return x;
    return gcd(y,x%y);
}
int main(int argc, const char * argv[]) {
    int i,j,m,n=20,o,N;
    cin>>N;
    fact[0]=1;
    for(i=1;i<=n;i++)fact[i]=fact[i-1]*i;
    bc[0]=0;
    for(i=1;i<(1<<n);i++)bc[i]=bc[i^(i&-i)]+1;
    c[0][0]=1;
    for(i=1;i<=n;i++){
        c[i][0]=c[i][i]=1;
        for(j=1;j<i;j++)c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    dp[0][0]=dp[0][1]=1;
    for(i=1;i<=n;i++){
        dp[i][0]=1;
        for(j=1;j<i;j++)dp[i][j]=dp[i-1][j]+dp[i][j-1];
        dp[i][i]=dp[i][i+1]=dp[i][i-1];
    }
    while (N--) {
        long long ans=0,ans2;
        scanf("%d%d%d",&o,&m,&n);
        for(i=0;i<n;i++){
            scanf("%d",&tmp[1<<i]);
        }
        sum[0]=0;
        for(i=1;i<(1<<n);i++)sum[i]=sum[i^(i&-i)]+tmp[i&-i];
        for(i=0;i<(1<<n);i++){
            if(sum[i]>=o&&bc[i]<=m+1){
                ans+=c[m][bc[i]-1]*dp[bc[i]-1][bc[i]]*fact[bc[i]-1]*fact[bc[i]]*fact[n+m-2*bc[i]+1];
                if(bc[i]==n&&bc[i]<=m)ans+=dp[m][n]*fact[n]*fact[m];
            }
        }
        ans2=fact[n+m];
        long long t=gcd(ans,ans2);
        ans/=t;
        ans2/=t;
        if(ans==0)printf("0/1\n");
        else printf("%lld/%lld\n",ans,ans2);
    }
    return 0;
}
