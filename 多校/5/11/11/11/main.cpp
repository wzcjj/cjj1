//
//  main.cpp
//  11
//
//  Created by wzcjj on 16/8/2.
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
#define maxn 1005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn],b[maxn];
long long dp[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d%d",&n,&m)!=EOF) {
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d",&b[i]);
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                if(a[i]==b[j])dp[i][j]+=dp[i-1][j-1]+1;
                dp[i][j]=(dp[i][j]+P)%P;
            }
        }
        printf("%lld\n",dp[n][m]);
    }
    return 0;
}
