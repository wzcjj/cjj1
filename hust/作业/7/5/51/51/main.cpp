//
//  main.cpp
//  51
//
//  Created by wzcjj on 15/11/19.
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
#define maxn 105
#define maxm 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

int a[maxn],c[maxn];
int dp[2][maxm];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (true) {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)scanf("%d",&c[i]);
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;
        for(i=1;i<=n;i++){
            for(j=0;j<=m;j++){
                if(dp[1^(i&1)][j]>=0)dp[i&1][j]=0;
                else if(j>=a[i]){
                    if(dp[1^(i&1)][j-a[i]]>=0)dp[i&1][j]=1;
                    else if(dp[i&1][j-a[i]]>=0&&dp[i&1][j-a[i]]<c[i])dp[i&1][j]=dp[i&1][j-a[i]]+1;
                }
            }
        }
        int ans=0;
        for(i=1;i<=m;i++)if(dp[n&1][i]>=0)ans++;
        printf("%d\n",ans);
    }
    return 0;
}
