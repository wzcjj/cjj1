//
//  main.cpp
//  9
//
//  Created by wzcjj on 16/9/17.
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
#define maxn 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct edge{
    int x,y,i,j,v;
};
struct node{
    int y,v,i,ma;
};
vector<node> a[maxn];
edge b[maxn];
//int fat[maxn];
int ma[maxn][2];
void dfs(int x,int fa){
    //fat[x]=fa;
    for(int i=0;i<a[x].size();i++)if(a[x][i].y!=fa){
        dfs(a[x][i].y,x);
        a[x][i].ma=ma[a[x][i].y][0];
        if(ma[x][0]<a[x][i].ma+a[x][i].v){
            ma[x][1]=ma[x][0];
            ma[x][0]=a[x][i].ma+a[x][i].v;
        }
        else if(ma[x][1]<a[x][i].ma+a[x][i].v)ma[x][1]=a[x][i].ma+a[x][i].v;;
    }
}
void dfs1(int x,int fa){
    for(int i=0;i<a[x].size();i++)if(a[x][i].y!=fa){
        int p,q;
        if(b[a[x][i].i].x==x){
            p=b[a[x][i].i].y;
            q=b[a[x][i].i].j;
        }
        else {
            p=b[a[x][i].i].x;
            q=b[a[x][i].i].i;
        }
        if(a[x][i].ma+a[x][i].v==ma[x][0]){
            a[p][q].ma=ma[x][1];
        }
        else a[p][q].ma=ma[x][0];
        if(ma[p][0]<a[p][q].ma+a[p][q].v){
            ma[p][1]=ma[p][0];
            ma[p][0]=a[p][q].ma+a[p][q].v;
        }
        else {
            if(ma[p][1]<a[p][q].ma+a[p][q].v)ma[p][1]=a[p][q].ma+a[p][q].v;
        }
        dfs1(a[x][i].y,x);
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        memset(ma, 0, sizeof(ma));
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<n;i++){
            scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].v);
            node t;
            t.y=b[i].y;
            t.v=b[i].v;
            t.i=i;
            t.ma=0;
            b[i].i=a[b[i].x].size();
            a[b[i].x].push_back(t);
            b[i].j=a[b[i].y].size();
            t.y=b[i].x;
            a[b[i].y].push_back(t);
        }
        dfs(1,-1);
        dfs1(1,-1);
        long long ans=0;
        for(i=1;i<n;i++){
            ans+=max(a[b[i].x][b[i].i].ma,a[b[i].y][b[i].j].ma);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
