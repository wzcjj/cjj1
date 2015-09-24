//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/8/24.
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
#include <cstdio>
#include <ctime>
#include <bitset>
#include <functional>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;

int deep[maxn],v[maxn],fa[maxn],c[maxn];
bool flag[maxn],fi[maxn],fir[maxn];
vector<int>a[maxn];
queue<int>b;
int getfa(int x){
    if(x!=fa[x])fa[x]=getfa(fa[x]);
    return fa[x];
}
int dfs(int x){
    fi[x]=true;
    flag[x]=true;
    for(int i=0;i<a[x].size();i++){
        a[x][i]=getfa(a[x][i]);
        if(a[x][i]==x)continue;
        if(flag[a[x][i]]){
            for(int j=0;j<a[x].size();j++){
                a[a[x][i]].push_back(a[x][j]);
            }
            fa[x]=a[x][i];
            flag[x]=false;
            v[a[x][i]]+=v[x];
            v[x]=0;
            return a[x][i];
        }
        else if(!fi[a[x][i]]){
            int t=dfs(a[x][i]);
            if(t){
                if(t!=x){
                    for(int j=0;j<a[x].size();j++){
                        a[t].push_back(a[x][j]);
                    }
                    fa[x]=t;
                    flag[x]=false;
                    v[t]+=v[x];
                    v[x]=0;
                    return t;
                }
            }
        }
    }
    flag[x]=false;
    return 0;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    memset(flag,0,sizeof(flag));
    while (scanf("%d%d",&n,&m)!=EOF) {
        for(i=1;i<=n;i++)a[i].clear();
        memset(fi,0,sizeof(fi));
        memset(fir,0,sizeof(fir));
        memset(c,0,sizeof(c));
        memset(deep, 0, sizeof(deep));
        for(i=1;i<=n;i++)v[i]=1;
        for(i=1;i<=n;i++)fa[i]=i;
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            fir[y]=true;
        }
        for(i=1;i<=n;i++)if(!fir[i])dfs(i);
        for(i=1;i<=n;i++)
            if(!fi[i])dfs(i);
        memset(fi,0,sizeof(fi));
        for(i=1;i<=n;i++)if(v[i]){
            for(j=0;j<a[i].size();j++){
                a[i][j]=getfa(a[i][j]);
                if(a[i][j]==i)continue;
                fi[a[i][j]]=true;
                c[a[i][j]]++;
            }
        }
        for(i=1;i<=n;i++)if(!fi[i]&&v[i]){
            b.push(i);
            deep[i]=v[i];
            flag[i]=true;
        }
        while(!b.empty()){
            int x=b.front();
            b.pop();
            flag[x]=false;
            for(i=0;i<a[x].size();i++)if(a[x][i]!=x){
                c[a[x][i]]--;
                if(deep[x]+v[a[x][i]]>deep[a[x][i]]){
                    deep[a[x][i]]=deep[x]+v[a[x][i]];
                }
                if(!flag[a[x][i]]&&c[a[x][i]]==0){
                    b.push(a[x][i]);
                    flag[a[x][i]]=true;
                }
            }
        }
        int ans=0;
        for(i=1;i<=n;i++){
            if(deep[i]>ans)ans=deep[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
