//
//  main.cpp
//  2
//
//  Created by wzcjj on 15/11/17.
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
#define maxn 305
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

int a[maxn],b[maxn];
int dp[35][maxn];
int sum[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    b[0]=0;
    for(i=1;i<=n;i++)b[i]=b[i-1]+a[i];
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            dp[i][j]=INF;
        }
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            sum[i][j]=b[j]-b[(i+j)>>1]-b[(i+j-1)>>1]+b[i-1];
        }
    }
    for(i=1;i<=n;i++){
        dp[1][i]=sum[1][i];
    }
    for(i=2;i<=m;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=j;k++){
                dp[i][j]=min(dp[i][j],dp[i-1][k]+sum[k+1][j]);
            }
        }
    }
    printf("%d\n",dp[m][n]);
    return 0;
}
