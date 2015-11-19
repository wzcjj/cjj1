//
//  main.cpp
//  5
//
//  Created by wzcjj on 15/10/30.
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
#define P 1000000007
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;

int a[maxn];
int b[maxn][maxn];
int dp[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k;
    cin>>N;
    memset(b,0,sizeof(b));
    while (N--) {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&b[i][j]);
            }
        }
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        if(a[1]!=-1){
            for(i=1;i<=m;i++)if(i!=a[1])dp[1][i]=-INF;
        }
        for(i=2;i<=n;i++){
            if(a[i]!=-1){
                for(j=1;j<=m;j++){
                    if(j==a[i]){
                        for(k=1;k<=m;k++){
                            dp[i][j]=max(dp[i][j], dp[i-1][k]+b[k][j]);
                        }
                    }
                    else{
                        dp[i][j]=-INF;
                    }
                }
            }
            else{
                for(j=1;j<=m;j++){
                    for(k=1;k<=m;k++){
                        dp[i][j]=max(dp[i][j], dp[i-1][k]+b[k][j]);
                    }
                }
            }
        }
        int ans=0;
        for(i=1;i<=m;i++)ans=max(ans, dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
