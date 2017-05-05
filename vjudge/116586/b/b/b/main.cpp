//
//  main.cpp
//  b
//
//  Created by wzcjj on 16/7/17.
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
#define maxn 105
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct node{
    int num,fi,ad;
};
struct nod{
    int c;
    int v;
};
node a[maxn];
nod dp[maxn][maxn];
int ans[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I=0,k;
    while (scanf("%d%d",&m,&n)!=EOF) {
        if(m==0&&n==0)break;
        I++;
        for(i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].num,&a[i].fi,&a[i].ad);
        }
        memset(dp,0,sizeof(dp));
        for(j=0;j<=m;j++){
            dp[n][j].v=a[n].num*(a[n].fi+j/(j+10.1)*a[n].ad)/100+0.5;
            dp[n][j].c=j;
        }
        for(i=n-1;i>=1;i--){
            for(j=0;j<=m;j++){
                for(k=0;k<=j;k++){
                    if(dp[i][j].v<=(int)(dp[i+1][j-k].v+a[i].num*(a[i].fi+k/(10.1+k)*a[i].ad)/100+0.5)){
                        dp[i][j].v=dp[i+1][j-k].v+a[i].num*(a[i].fi+k/(10.1+k)*a[i].ad)/100+0.5;
                        dp[i][j].c=k;
                    }
                }
            }
        }
        j=m;
        for(i=1;i<=n;i++){
            ans[i]=dp[i][j].c;
            j-=dp[i][j].c;
        }
        printf("Case %d: %d\n",I,dp[1][m].v);
        for(i=1;i<n;i++){
            printf("%d:%d ",i-1,ans[i]);
        }
        printf("%d:%d\n",n-1,ans[n]);
    }
    return 0;
}
