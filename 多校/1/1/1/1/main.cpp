//
//  main.cpp
//  1
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
#define maxn 100005
#define maxm 1000005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct node{
    int x,y,v;
    friend bool operator<(node x,node y){
        return x.v<y.v;
    }
};
struct edge{
    int y,v;
};
node a[maxm];
vector<edge>b[maxn];
int fa[maxn];
//bool flag[maxm];
double ans1;
int n;
int getfa(int x){
    if(fa[x]!=x)fa[x]=getfa(fa[x]);
    return fa[x];
}
int dfs(int x,int fat){
    int cnt=1;
    for(int i=0;i<b[x].size();i++)if(b[x][i].y!=fat){
        int now=dfs(b[x][i].y,x);
        ans1+=2.0*b[x][i].v*now*(n-now)/n/(n-1);
        cnt+=now;
    }
    return cnt;
}
int main(int argc, const char * argv[]) {
    int i,j,m,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
        }
        sort(a+1,a+1+m);
        for(i=1;i<=n;i++)b[i].clear();
        long long ans=0;
        ans1=0;
        for(i=1;i<=n;i++){
            fa[i]=i;
        }
        int cnt=0;
        for(i=1;i<=m;i++){
            if(cnt==n-1)break;
            if(getfa(a[i].x)!=getfa(a[i].y)){
                ans+=a[i].v;
                fa[getfa(a[i].x)]=getfa(a[i].y);
                cnt++;
                //flag[i]=true;
                edge t;
                t.y=a[i].y;
                t.v=a[i].v;
                b[a[i].x].push_back(t);
                t.y=a[i].x;
                b[a[i].y].push_back(t);
            }
        }
        dfs(1,-1);
        printf("%lld %.2lf\n",ans,ans1);
    }
    return 0;
}
