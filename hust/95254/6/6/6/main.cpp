//
//  main.cpp
//  6
//
//  Created by wzcjj on 15/10/14.
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
#define INF 1000000000
using namespace std;

int a[maxn];
int b[maxn];
int dp[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k;
    cin>>N;
    int I=0;
    while (N--) {
        I++;
        scanf("%d",&n);
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)dp[i][j]=INF;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        b[0]=0;
        for(i=1;i<=n;i++)b[i]=b[i-1]+a[i];
        for(i=1;i<=n;i++)dp[i][i]=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n-i;j++){
                for(k=j;k<=i+j;k++){
                    int t=a[j]*(k-j);
                    if(k<i+j)t+=dp[k+1][i+j]+(b[i+j]-b[k])*(k-j+1);
                    if(k>j)t+=dp[j+1][k];
                    if(dp[j][i+j]>t){
                        dp[j][i+j]=t;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",I,dp[1][n]);
    }
    return 0;
}