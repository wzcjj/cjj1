//
//  main.cpp
//  8
//
//  Created by wzcjj on 16/8/7.
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
#define maxn 1001
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
long long dp[2][maxn][3][3];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k,l;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        bool sign=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0]=1;
        for(i=1;i<=n;i++){
            sign=!sign;
            for(j=0;j<=m;j++){
                for(k=0;k<=2;k++){
                    for(l=0;l<=2;l++){
                        dp[sign][j][k][l]=dp[!sign][j][k][l];
                        if(j>=a[i])dp[sign][j][k][l]+=dp[!sign][j-a[i]][k][l];
                        if(j>=a[i]&&k)dp[sign][j][k][l]+=dp[!sign][j-a[i]][k-1][l];
                        if(l)dp[sign][j][k][l]+=dp[!sign][j][k][l-1];
                        dp[sign][j][k][l]%=P;
                    }
                }
            }
        }
        long long ans=0;
        for(j=1;j<=m;j++)ans+=dp[sign][j][2][2];
        ans*=4;
        ans%=P;
        printf("%lld\n",ans);
    }
    return 0;
}
