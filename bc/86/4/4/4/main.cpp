//
//  main.cpp
//  4
//
//  Created by wzcjj on 16/8/6.
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
#define maxn 55
#define P 998244353
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

vector<int> a[maxn];
int b[maxn];
long long dp[maxn][maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k,q,l;
    cin>>N;
    while (N--) {
        scanf("%d%d%d%d",&n,&m,&k,&q);
        memset(dp, 0, sizeof(dp));
        for(i=1;i<=n;i++){
            a[i].clear();
        }
        for(i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                for(l=1;l<=n;l++){
                    if(abs(b[i]-b[j])<=k&&abs(b[i]-b[l])<=k&&abs(b[l]-b[j])<=k)dp[i][j][l]++;
                }
            }
        }
        for(i=n;i>=1;i--){
            for(j=n;j>=1;j--){
                for(l=n;l>=1;l--){
                    if(dp[i][j][l]){
                        for(int i1=0;i1<a[i].size();i1++){
                            for(int j1=0;j1<a[j].size();j1++){
                                for(int l1=0;l1<a[l].size();l1++){
                                    dp[i][j][l]=(dp[i][j][l]+dp[a[i][i1]][a[j][j1]][a[l][l1]])%P;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(i=1;i<=q;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            printf("%lld\n",dp[x][y][z]);
        }
    }
    return 0;
}
