//
//  main.cpp
//  10
//
//  Created by wzcjj on 15/8/13.
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
#define maxn 100005
#define P 258280327
#define INF 2100000000
using namespace std;

int d[maxn];
long long dp[15][15],dp1[15][15];
int aa(int x){
    if(x>9)return x-9;
    else return x;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,a,b,k;
    cin>>N;
    while (N--) {
        scanf("%d%d%d",&n,&a,&b);
        for(i=1;i<=n;i++)scanf("%d",&d[i]);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=1;i<=n;i++){
            memset(dp1,0,sizeof(dp1));
            for(j=0;j<=9;j++){
                for(k=0;k<=9;k++){
                    dp1[aa(j+d[i])][k]+=dp[j][k];
                    dp1[j][aa(k+d[i])]+=dp[j][k];
                }
            }
            for(j=0;j<=9;j++){
                for(k=0;k<=9;k++){
                    dp[j][k]=dp1[j][k]%P;
                }
            }
        }
        printf("%lld\n",dp[a][b]+dp[a][0]+dp[0][b]);
    }
    return 0;
}
