//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/7/3.
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
#define maxm 2005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct jia{
    int a,b;
};
struct yi{
    int a,b,c;
};
struct bing{
    int a,b;
};
jia a[maxn];
yi b[maxn];
bing c[maxn];
int dp[maxn][maxm];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k;
    N=1;
    while (N--) {
        int cnt1=0,cnt2=0,cnt3=0;
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            int w;
            scanf("%d",&w);
            if(w==1){
                cnt1++;
                scanf("%d%d",&a[cnt1].a,&a[cnt1].b);
            }
            else if(w==2){
                cnt2++;
                scanf("%d%d%d",&b[cnt2].a,&b[cnt2].b,&b[cnt2].c);
            }
            else {
                cnt3++;
                scanf("%d%d",&c[cnt3].a,&c[cnt3].b);
            }
        }
        for(i=1;i<=cnt1;i++){
            for(j=0;j<=m;j++){
                dp[i][j]=dp[i-1][j];
                for(k=a[i].b/a[i].a/2;k<=j;k++){
                    if(dp[i][j]<dp[i-1][j-k]+a[i].a*k*k-a[i].b*k)dp[i][j]=dp[i-1][j-k]+a[i].a*k*k-a[i].b*k;
                }
            }
        }
        for(i=1;i<=cnt2;i++){
            for(j=0;j<=m;j++){
                dp[i+cnt1][j]=dp[i-1+cnt1][j];
                for(k=1;k<=b[i].c;k++){
                    if(j>=k*b[i].b&&dp[i+cnt1][j]<dp[i+cnt1-1][j-k*b[i].b]+k*b[i].a)dp[i+cnt1][j]=dp[i+cnt1-1][j-k*b[i].b]+k*b[i].a;
                }
            }
        }
        for(i=1;i<=cnt3;i++){
            for(j=0;j<=m;j++){
                dp[i+cnt1+cnt2][j]=dp[i+cnt1+cnt2-1][j];
                if(j>=c[i].b&&dp[i+cnt1+cnt2][j]<dp[i+cnt1+cnt2][j-c[i].b]+c[i].a)dp[i+cnt1+cnt2][j]=dp[i+cnt1+cnt2][j-c[i].b]+c[i].a;
            }
        }
        /*for(i=1;i<=n;i++){
            for(j=1;j<=m;j++)printf("%d ",dp[i][j]);
            printf("\n");
        }*/
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
