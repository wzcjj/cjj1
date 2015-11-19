//
//  main.cpp
//  1533
//
//  Created by wzcjj on 15/11/12.
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
#define maxn 10005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;
class MinCostFlow {
#define DATA_TYPE int
public:
    struct edge {
        int rev, y;
        DATA_TYPE value, cost;
    };
    struct Pi {
        int x, i;
        DATA_TYPE minflow;
    };
    vector<edge> flow[maxn];
    bool flag[maxn];
    DATA_TYPE dis[maxn];
    Pi pi[maxn];
    int n;
    queue<int> q;
    void init(int m = maxn - 1) {
        n = m;
        while(!q.empty())q.pop();
        for(int i = 1;i <= n; i ++) {
            flow[i].clear();
        }
    }
    void addedge(int x, int y, DATA_TYPE c, DATA_TYPE v) {
        edge t;
        t.value = v;
        t.rev = flow[y].size();
        t.y = y;
        t.cost = c;
        flow[x].push_back(t);
        t.value = 0;
        t.rev = flow[x].size() - 1;
        t.y = x;
        t.cost = -c;
        flow[y].push_back(t);
    }
    DATA_TYPE spfa(int s, int t) {
        for(int i = 1; i <= n; i ++) {
            flag[i] = 0;
            pi[i].x = pi[i].i = pi[i].minflow = 0;
            dis[i] = INF;
        }
        dis[s] = 0;
        flag[s] = 1;
        pi[s].minflow = INF;
        q.push(s);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(int i = 0; i < flow[x].size(); i ++) if(dis[flow[x][i].y] > dis[x] + flow[x][i].cost && flow[x][i].value) {
                int y = flow[x][i].y;
                dis[y] = dis[x] + flow[x][i].cost;
                pi[y].x = x;
                pi[y].i = i;
                pi[y].minflow = min(pi[x].minflow, flow[x][i].value);
                if(!flag[y]) {
                    flag[y] = 1;
                    q.push(y);
                }
            }
            flag[x] = 0;
        }
        return dis[t];
    }
    DATA_TYPE mincostflow(int s, int t) {
        DATA_TYPE ans = 0;
        while(spfa(s, t) != INF) {
            int p = t;
            DATA_TYPE v = pi[p].minflow;
            while(pi[p].x) {
                flow[pi[p].x][pi[p].i].value -= v;
                flow[flow[pi[p].x][pi[p].i].y][flow[pi[p].x][pi[p].i].rev].value += v;
                ans += flow[pi[p].x][pi[p].i].cost * v;
                p = pi[p].x;
            }
        }
        return ans;
    }
};
MinCostFlow net;
int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d%d",&n,&m)!=EOF) {
        if(n==0&&m==0)break;
        char c;
        net.init(n*m+2);
        for(i=1;i<=n;i++){
            scanf("%c",&c);
            for(j=1;j<=m;j++){
                scanf("%c",&c);
                if(c=='m'){
                    net.addedge(n*m+1, (i-1)*m+j, 0, 1);
                }
                else if(c=='H'){
                    net.addedge((i-1)*m+j, n*m+2, 0, 1);
                }
                if(i>1)net.addedge((i-1)*m+j, (i-1-1)*m+j, 1, INF);
                if(i<n)net.addedge((i-1)*m+j, (i-1+1)*m+j, 1, INF);
                if(j>1)net.addedge((i-1)*m+j, (i-1)*m+j-1, 1, INF);
                if(j<m)net.addedge((i-1)*m+j, (i-1)*m+j+1, 1, INF);
            }
        }
        DATA_TYPE ans = net.mincostflow(n*m+1, n*m+2);
        printf("%d\n",ans);
    }
    return 0;
}
