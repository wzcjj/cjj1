//
//  main.cpp
//  4
//
//  Created by wzcjj on 15/9/24.
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
#define maxn 3005
#define maxm 40005
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn][maxn];
vector<int> b[maxm];
vector<int> c[maxn];
bool flag[maxm],fl[maxn];
int d[maxm];
int ans[maxm];
int past[maxm];
queue<int> q;
int an[maxm];
int main(int argc, const char * argv[]) {
    int i,j,m,n,k;
    while (scanf("%d%d%d",&n,&m,&k)!=EOF) {
        memset(a, -1, sizeof(a));
        memset(flag, 0, sizeof(flag));
        memset(ans,-1,sizeof(ans));
        for(i=1;i<=n;i++)c[i].clear();
        for(i=1;i<=2*m;i++)b[i].clear();
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y]=2*i-1;
            a[y][x]=2*i;
            d[2*i-1]=y;
            d[2*i]=x;
            c[x].push_back(2*i-1);
            c[y].push_back(2*i);
        }
        for(i=1;i<=k;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(a[x][y]!=-1)b[a[x][y]].push_back(z);
        }
        d[0]=1;
        a[1][1]=0;
        ans[0]=0;
        q.push(0);
        while(!q.empty()) {
            int x=q.front();
            q.pop();
                memset(fl, 0, sizeof(fl));
                for(j=0;j<b[x].size();j++){
                    fl[b[x][j]]=true;
                }
                for(j=1;j<=n;j++)if(!fl[j]){
                    if(a[d[x]][j]!=-1&&!flag[a[d[x]][j]]){
                        flag[a[d[x]][j]]=true;
                        q.push(a[d[x]][j]);
                        if(ans[a[d[x]][j]]==-1){
                            ans[a[d[x]][j]]=ans[x]+1;
                            past[a[d[x]][j]]=x;
                        }
                    }
                }
        }
        int ma=-1;
        for(i=1;i<=n;i++)if(a[i][n]!=-1){
            if(ma==-1||ma>ans[a[i][n]]){
                ma=ans[a[i][n]];
                j=a[i][n];
            }
        }
        if(ma!=-1){
            printf("%d\n1",ma);
            for(i=1;i<=ma;i++){
                an[ma-i+1]=d[j];
                j=past[j];
            }
            for(i=1;i<=ma;i++)printf(" %d",an[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}
