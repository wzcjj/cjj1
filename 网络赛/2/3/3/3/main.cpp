//
//  main.cpp
//  3
//
//  Created by wzcjj on 15/9/19.
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
#define maxn 20005
#define P 1000000007
#define INF 2100000000
using namespace std;

#define BUFSIZE 100000000
char buf[BUFSIZE], *pt = buf;
#define scan(t) do { \
t = 0; \
while (!((*pt) >= '0' && (*pt) <= '9')) pt ++; \
while (((*pt) >= '0' && (*pt) <= '9')) t = t * 10 + (*(pt ++)) - '0'; \
} while (0)


vector<int> a[maxn];
int de[maxn],su[maxn];
int fa[maxn][20];
void dfs(int x,int dee,int fat){
    de[x]=dee;
    fa[x][0]=fat;
    for(int i=1;(1<<i)<=dee;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fat){
        dfs(a[x][i],dee+1,x);
    }
}
int lca(int x,int y){
    if(de[x]<de[y]){
        int t=de[y]-de[x];
        int i=0;
        while(t){
            if(t&(1<<i)){
                y=fa[y][i];
                t-=(1<<i);
            }
            i++;
        }
    }
    else if(de[x]>de[y]){
        int t=de[x]-de[y];
        int i=0;
        while(t){
            if(t&(1<<i)){
                x=fa[x][i];
                t-=(1<<i);
            }
            i++;
        }
    }
    if(x==y)return x;
    int i=0;
    while((1<<i)<de[x])i++;
    for(;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
void dfs2(int x,int fat){
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fat){
        dfs2(a[x][i],x);
        su[x]+=su[a[x][i]];
    }
}
int main(int argc, const char * argv[]) {
    fread(buf, 1, BUFSIZE, stdin);
    int i,j,m,n,N,I=0;
    scan(N);
    while (N--) {
        I++;
        scan(n);
        scan(m);
        for(i=1;i<=n;i++)a[i].clear();
        memset(fa,0,sizeof(fa));
        memset(su,0,sizeof(su));
        for(i=1;i<n;i++){
            int x,y;
            scan(x);
            scan(y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        dfs(1,1,0);
        for(i=n;i<=m;i++){
            int x,y;
            scan(x);
            scan(y);
            su[x]++;
            su[y]++;
            su[lca(x,y)]-=2;
        }
        dfs2(1,0);
        int ans=INF;
        for(i=2;i<=n;i++)if(ans>su[i]+1)ans=su[i]+1;
        printf("Case #%d: %d\n",I,ans);
    }
    return 0;
}
