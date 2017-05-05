//
//  main.cpp
//  1
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
#define maxn 210005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
#define node(a,b) ((a-1)*(k+1)+b)
using namespace std;

struct edge {
    int y,v;
};
vector<edge> a[maxn];
long long ans[maxn];
bool flag[maxn];
queue<int> q;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k;
    scanf("%d%d%d",&n,&m,&k);
    memset(ans,-1,sizeof(ans));
    memset(flag,0,sizeof(flag));
    for(i=1;i<=m;i++){
        edge t;
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        t.v=v;
        for(j=0;j<=k;j++) {
            t.y=node(y,j);
            a[node(x,j)].push_back(t);
            t.y=node(x,j);
            a[node(y,j)].push_back(t);
        }
        t.v=0;
        for(j=0;j<k;j++) {
            t.y=node(y,j+1);
            a[node(x,j)].push_back(t);
            t.y=node(x,j+1);
            a[node(y,j)].push_back(t);
        }
    }
    for(i=1;i<=n;i++){
        for(j=0;j<k;j++){
            edge t;
            t.y=node(i,j+1);
            t.v=0;
            a[node(i,j)].push_back(t);
        }
    }
    ans[node(1,0)]=0;
    q.push(node(1,0));
    flag[0]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        flag[x]=false;
        for(i=0;i<a[x].size();i++){
            if(ans[a[x][i].y]==-1||ans[a[x][i].y]>ans[x]+a[x][i].v){
                ans[a[x][i].y]=ans[x]+a[x][i].v;
                if(!flag[a[x][i].y]){
                    flag[a[x][i].y]=true;
                    q.push(a[x][i].y);
                }
            }
        }
    }
    //for(i=node(1,0);i<=node(n,k);i++)cout<<ans[i]<<' ';
    cout<<ans[node(n,k)]<<endl;
    return 0;
}
