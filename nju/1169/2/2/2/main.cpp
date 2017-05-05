//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/1/12.
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
#define maxn 10005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

struct lesson{
    int t,a;
};
struct pg{
    int c,d;
};
vector<lesson> a[maxn];
pg b[maxn];
int c[105];
int dp[maxn][105];
bool cmp(pg x,pg y){
    if(x.c==y.c)return x.d<y.d;
    else return x.c<y.c;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k,ti;
    while(scanf("%d%d%d",&ti,&n,&m)){
        if(n==0&&ti==0&&m==0)break;
        for(i=0;i<=ti;i++)a[i].clear();
        memset(dp,-1,sizeof(dp));
        for(i=1;i<=n;i++){
            int s,t,aa;
            scanf("%d%d%d",&s,&t,&aa);
            lesson tmp;
            tmp.t=t;
            tmp.a=aa;
            a[s].push_back(tmp);
        }
        for(i=1;i<=m;i++)scanf("%d%d",&b[i].c,&b[i].d);
        sort(b+1,b+1+m,cmp);
        int minn=INF,last=1;
        for(i=1;i<=m;i++){
            for(j=last;j<=b[i].c;j++)c[j]=minn;
            last=b[i].c;
            if(minn>b[i].d)minn=b[i].d;
        }
        for(j=last;j<=100;j++)c[j]=minn;
        dp[0][1]=0;
        for(i=0;i<=ti;i++){
            for(j=1;j<=100;j++)if(dp[i][j]>=0){
                if(dp[i+1][j]==-1||dp[i+1][j]<dp[i][j])dp[i+1][j]=dp[i][j];
                for(k=0;k<a[i].size();k++){
                    if(i+a[i][k].t<=ti&&(dp[i+a[i][k].t][a[i][k].a]==-1||dp[i+a[i][k].t][a[i][k].a]<dp[i][j]))dp[i+a[i][k].t][a[i][k].a]=dp[i][j];
                }
                if(i+c[j]<=ti&&(dp[i+c[j]][j]==-1||dp[i+c[j]][j]<dp[i][j]+1))dp[i+c[j]][j]=dp[i][j]+1;
            }
        }
        int maxx=0;
        for(i=1;i<=100;i++){
            if(dp[ti][i]>maxx)maxx=dp[ti][i];
        }
        printf("%d\n",maxx);
    }
    return 0;
}
