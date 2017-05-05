//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/4/1.
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
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;
class NetFlow {
public:
    struct edge {
        int value, rev, y;
    };
    vector<edge> flow[maxn];
    bool flag[maxn];
    int dis[maxn];
    int n;
    queue<int> q;
    void init(int m = maxn - 1) {
        n = m;
        while(!q.empty())q.pop();
        for(int i = 1;i <= n; i ++) {
            flow[i].clear();
        }
    }
    void addedge(int x, int y, int v = 1) {
        edge t;
        t.value = v;
        t.rev = flow[y].size();
        t.y = y;
        flow[x].push_back(t);
        t.value = 0;
        t.rev = flow[x].size() - 1;
        t.y = x;
        flow[y].push_back(t);
    }
    void addedge_u(int x, int y, int v = 1) {
        edge t;
        t.value = v;
        t.rev = flow[y].size();
        t.y = y;
        flow[x].push_back(t);
        t.rev = flow[x].size() - 1;
        t.y = x;
        flow[y].push_back(t);
    }
    int bfs(int s, int t) {
        for(int i = 1; i <= n; i ++) {
            flag[i] = 0;
        }
        dis[s] = 0;
        flag[s] = 1;
        q.push(s);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(int i = 0; i < flow[x].size(); i ++) if(!flag[flow[x][i].y] && flow[x][i].value) {
                int y = flow[x][i].y;
                flag[y] = 1;
                q.push(y);
                dis[y] = dis[x] + 1;
            }
        }
        return flag[t];
    }
    int dfs(int x, int v, int t) {
        int val = 0;
        if(x == t) {
            return v;
        }
        int used = 0;
        for(int i = 0; i < flow[x].size(); i ++) if(!flag[flow[x][i].y] && flow[x][i].value && dis[flow[x][i].y] > dis[x] && (val = dfs(flow[x][i].y, min(v - used, flow[x][i].value), t))) {
            flow[x][i].value -= val;
            flow[flow[x][i].y][flow[x][i].rev].value += val;
            used += val;
            if(used == v)return v;
        }
        if(used == 0)flag[x] = true;
        return used;
    }
    int dinic(int s, int t) {
        int ans = 0;
        while(bfs(s, t)) {
            for(int i = 1; i <= n; i ++) {
                flag[i] = 0;
            }
            while(int v = dfs(s, INF, t)) {
                ans += v;
                for(int i = 1; i <= n; i ++) {
                    flag[i] = 0;
                }
            }
        }
        return ans;
    }
};
NetFlow net;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        net.init(n*m+2);
        int cnt= 0;
        for(i=1;i<=n;i++){
            char c;
            scanf("%c",&c);
            for(j=1;j<=m;j++){
                scanf("%c",&c);
                if(c=='*'){
                    cnt++;
                    if((i+j)&1){
                        net.addedge(n*m+1, (i-1)*m+j);
                    }
                    else {
                        net.addedge((i-1)*m+j, n*m+2);
                    }
                }
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++)if((i+j)&1){
                if(i<n){
                    net.addedge((i-1)*m+j, i*m+j);
                }
                if(i>1){
                    net.addedge((i-1)*m+j, (i-2)*m+j);
                }
                if(j>1){
                    net.addedge((i-1)*m+j, (i-1)*m+j-1);
                }
                if(j<m){
                    net.addedge((i-1)*m+j, (i-1)*m+j+1);
                }
            }
        }
        printf("%d\n",cnt-net.dinic(n*m+1, n*m+2));
    }
    return 0;
}