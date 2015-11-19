//
//  main.cpp
//  6
//
//  Created by wzcjj on 15/11/18.
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
#define maxn 55
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

char a[maxn][maxn];
int sum[maxn][maxn];
int dp[maxn][maxn][2505],dp1[maxn][2505];
int main(int argc, const char * argv[]) {
    int i,j,m,n,o,N,k,l;
    N=1;
    while (N--) {
        scanf("%d%d%d",&n,&m,&o);
        for(i=1;i<=n;i++){
            scanf("%c",&a[i][i]);
            for(j=1;j<=m;j++){
                scanf("%c",&a[i][j]);
            }
        }
        for(i=1;i<=n;i++){
            sum[i][0]=0;
            for(j=1;j<=m;j++){
                sum[i][j]=sum[i][j-1]+a[i][j]-'0';
            }
        }
        memset(dp, 0, sizeof(dp));
        memset(dp1, 0, sizeof(dp1));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                for(k=1;k<=o;k++){
                    for(l=1;l<=j;l++){
                        dp[i][j][k]=max(dp[i][j][k], dp[i][l-1][k-1]+max(sum[i][j]-sum[i][l-1], j-l+1-(sum[i][j]-sum[i][l-1])));
                    }
                }
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=o;j++){
                for(k=0;k<=j;k++){
                    dp1[i][j]=max(dp1[i][j], dp1[i-1][k]+dp[i][m][j-k]);
                }
            }
        }
        printf("%d\n",dp1[n][o]);
    }
    return 0;
}
