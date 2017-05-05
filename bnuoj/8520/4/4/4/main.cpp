//
//  main.cpp
//  4
//
//  Created by wzcjj on 16/10/2.
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
#define maxn 3005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
int b[maxn][maxn];
int dp[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,l,k;
    N=1;
    while (N--) {
        scanf("%d%d%d",&n,&m,&l);
        memset(b, 0, sizeof(b));
        memset(dp, 0, sizeof(dp));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d",&k);
            for(j=1;j<=k;j++){
                int x;
                scanf("%d",&x);
                b[i][x]++;
            }
        }
        for(i=1;i<=m;i++){
            
        }
    }
    return 0;
}
