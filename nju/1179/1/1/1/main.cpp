//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/3/25.
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
#define maxn 5005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

int dp[maxn][maxn];
char s1[maxn],s2[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    N=1;
    while (N--) {
        scanf("%s%s",s1,s2);
        m=strlen(s1);
        n=strlen(s2);
        memset(dp,127,sizeof(dp));
        dp[0][0]=0;
        for(i=1;i<=m;i++)dp[i][0]=i;
        for(j=1;j<=n;j++)dp[0][j]=j;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j-1]+(s1[i-1]!=s2[j-1]);
                if(dp[i][j]>dp[i-1][j]+1)dp[i][j]=dp[i-1][j]+1;
                if(dp[i][j]>dp[i][j-1]+1)dp[i][j]=dp[i][j-1]+1;
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
