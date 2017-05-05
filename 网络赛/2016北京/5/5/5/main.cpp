//
//  main.cpp
//  5
//
//  Created by wzcjj on 16/9/24.
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

struct node{
    int y;
};
vector<node> a[maxn];
int de[maxn];
int fa[maxn][20];
void dfs(int x,int dee,int fat){
    de[x]=dee;
    fa[x][0]=fat;
    for(int i=1;(1<<i)<=dee;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=0;i<a[x].size();i++)if(a[x][i].y!=fat){
        dfs(a[x][i].y,dee+1,x);
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
vector<int> b[maxn];
struct node1{
    int y,v;
};
vector<node1> ans[maxn];
map<string,int> mapp;
void swap(int &x,int &y){
    int t=x;
    x=y;
    y=t;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    char s[10],s1[10];
    while (scanf("%d%d",&n,&m)!=EOF) {
        mapp.clear();
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<=n;i++)ans[i].clear();
        int cnt=0;
        for(i=1;i<=n;i++){
            scanf("%s",s);
            if(mapp[s]==0){
                mapp[s]=++cnt;
                b[cnt].clear();
                b[cnt].push_back(i);
            }
            else {
                b[mapp[s]].push_back(i);
            }
        }
        for(i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            node t;
            t.y=y;
            a[x].push_back(t);
            t.y=x;
            a[y].push_back(t);
        }
        dfs(1,1,-1);
        for(i=1;i<=m;i++){
            scanf("%s%s",s,s1);
            int x=mapp[s],y=mapp[s1];
            if(x==0||y==0){
                printf("-1\n");
                continue;
            }
            if(x>y)swap(x,y);
            if(ans[x].size()){
                int p=0,q=ans[x].size();
                while(p<q-1){
                    int mid=(p+q)>>1;
                    if(ans[x][mid].y<=y)p=mid;
                    else q=mid;
                }
                if(ans[x][p].y==y){
                    printf("%d\n",ans[x][p].v);
                    continue;
                }
            }
            int l=b[x][0],r=-1;
            while(true){
                int maxx=0,maxi=0;
                for(j=0;j<b[y].size();j++){
                    int t=lca(l, b[y][j]);
                    if(maxx<de[l]-de[t]+de[b[y][j]]-de[t]+1){
                        maxx=de[l]-de[t]+de[b[y][j]]-de[t]+1;
                        maxi=b[y][j];
                    }
                }
                if(r==maxi){
                    printf("%d\n",maxx);
                    if(x>y)swap(x,y);
                    node1 t;
                    t.y=y;
                    t.v=maxx;
                    ans[x].push_back(t);
                    break;
                }
                else{
                    r=maxi;
                    swap(x, y);
                    swap(l, r);
                }
            }
        }
    }
    return 0;
}
