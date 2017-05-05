//
//  main.cpp
//  2
//
//  Created by wzcjj on 15/11/21.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
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
#define maxn 1005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

int a[maxn][maxn];
int dp[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    
    while (scanf("%d%d",&n,&m)!=EOF) {
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        memset(dp,127,sizeof(dp));
        dp[1][0]=dp[0][1]=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if((i+j)&1){
                    if(i>1)dp[i][j]=min(dp[i][j],dp[i-2][j]+a[i][j]*a[i-1][j]);
                    if(i>1)dp[i][j]=min(dp[i][j],dp[i-1][j-1]+a[i][j]*a[i-1][j]);
                    if(j>1)dp[i][j]=min(dp[i][j],dp[i-1][j-1]+a[i][j]*a[i][j-1]);
                    if(j>1)dp[i][j]=min(dp[i][j],dp[i][j-2]+a[i][j-1]*a[i][j]);
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
