//
//  main.cpp
//  5
//
//  Created by wzcjj on 16/7/19.
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
#define maxn 15
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn][maxn];
bool flag[maxn][5];
int fl[maxn];
int ans,n;
void dfs(int x,int y,int deep){
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=fl[i];
    }
    if(cnt>=ans)return;
    if(deep==2*n){
        cnt=0;
        fl[x]+=a[1][x];
        for(int i=1;i<=n;i++)cnt+=!!fl[i];
        fl[x]-=a[1][x];
        if(ans>cnt)ans=cnt;
        return;
    }
    flag[x][y]=true;
    for(int i=1;i<=n;i++){
        if(y){
            if(!flag[i][0]&&!a[i][x])dfs(i,0,deep+1);
        }
        else{
            if(!flag[i][1]&&!a[x][i])dfs(i,1,deep+1);
        }
    }
    for(int i=1;i<=n;i++){
        if(y){
            if(!flag[i][0]&&a[i][x]){
                fl[i]++;
                dfs(i,0,deep+1);
                fl[i]--;
            }
        }
        else{
            if(!flag[i][1]&&a[x][i]){
                fl[x]++;
                dfs(i,1,deep+1);
                fl[x]--;
            }
        }
    }
    flag[x][y]=false;
}
int main(int argc, const char * argv[]) {
    int i,j,m,N;
    while (scanf("%d%d",&n,&m)!=EOF) {
        memset(a,0,sizeof(a));
        memset(flag,0,sizeof(flag));
        memset(fl,0,sizeof(fl));
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y]=1;
        }
        ans=INF;
        dfs(1,0,1);
        printf("%d\n",ans);
    }
    return 0;
}
