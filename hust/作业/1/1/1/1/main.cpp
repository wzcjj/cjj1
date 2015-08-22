//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/8/21.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 40005
#define P 1000000007
#define INF 2100000000
using namespace std;

struct node{
    int y,z;
};
vector<node> a[maxn];
int de[maxn],su[maxn];
int fa[maxn][20];
void dfs(int x,int dee,int sum,int fat){
    de[x]=dee;
    su[x]=sum;
    fa[x][0]=fat;
    for(int i=1;(1<<i)<=dee;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=0;i<a[x].size();i++)if(a[x][i].y!=fat){
        dfs(a[x][i].y,dee+1,sum+a[x][i].z,x);
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
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        memset(fa,-1,sizeof(fa));
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            node t;
            t.y=y;
            t.z=z;
            a[x].push_back(t);
            t.y=x;
            a[y].push_back(t);
        }
        dfs(1,0,0,-1);
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int t=lca(x,y);
            printf("%d\n",su[x]-su[t]+su[y]-su[t]);
        }
    }
    return 0;
}
