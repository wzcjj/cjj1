//
//  main.cpp
//  5
//
//  Created by wzcjj on 15/8/20.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 1005
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn],dp[maxn][2*maxn],b[maxn],c[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&c[i],&a[i],&b[i]);
        }
        dp[0][0]=0;
        for(i=1;i<=m;i++){
            for(j=0;j<=n;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=c[i]){
                    if(dp[i-1][j-c[i]]+a[i]+b[i]>dp[i][j])dp[i][j]=dp[i-1][j-c[i]]+a[i]+b[i];
                    if(dp[i][j-c[i]]+a[i]>dp[i][j])dp[i][j]=dp[i][j-c[i]]+a[i];
                }
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
