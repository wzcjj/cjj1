//
//  main.cpp
//  9
//
//  Created by wzcjj on 16/9/18.
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
#define maxn 305
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
int b[maxn];
long long c[maxn];
long long dp[maxn][maxn];
int gcd(int x,int y){
    if(y==0)return x;
    else return gcd(y,x%y);
}
int check(int x,int y){
    if(gcd(a[x],a[y])>1)return b[x]+b[y];
    else return 0;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        c[0]=0;
        for(i=1;i<=n;i++){
            c[i]=c[i-1]+b[i];
        }
        memset(dp, 0, sizeof(dp));
        for(i=1;i<n;i++){
            dp[i][i+1]=check(i, i+1);
        }
        for(i=3;i<=n;i++){
            for(j=1;j<=n-i+1;j++){
                for(int k=j;k<j+i-1;k++){
                    dp[j][j+i-1]=max(dp[j][j+i-1],dp[j][k]+dp[k+1][j+i-1]);
                }
                if(dp[j+1][j+i-2]==c[j+i-2]-c[j])dp[j][j+i-1]=max(dp[j][j+i-1],dp[j+1][j+i-2]+check(j, j+i-1));
            }
        }
        printf("%lld\n",dp[1][n]);
    }
    return 0;
}
