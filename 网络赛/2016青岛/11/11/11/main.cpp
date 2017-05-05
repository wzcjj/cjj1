//
//  main.cpp
//  11
//
//  Created by wzcjj on 16/9/17.
//  Copyright (c) 2016年 wzcjj. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <map>
#include <cstring>

#define MAX
#define INF 999999
#define MOD
#define MP make_pair
#define AA first
#define BB second
#define IS(X) cout << #X << " = " << X << endl;
#define PI 3.14159265
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef vector<int> VI;
typedef queue<int> QI;
typedef priority_queue<int> PQI;

const int maxnum = 1005;
const int maxn = 1005;
const int maxint = 999999;

int dist[maxnum];
int c[maxnum][maxnum];
int n, line;
int gra[maxnum][maxnum];
VI _prev[1005];
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
void Dijkstra(int n, int v, int *dist, VI *_prev, int c[maxnum][maxnum])
{
    bool s[maxnum];
    for(int i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];
        s[i] = 0;
        if(dist[i] < maxint)
            _prev[i].push_back(v);
    }
    dist[v] = 0;
    s[v] = 1;
    
    for(int i=2; i<=n; ++i)
    {
        int tmp = maxint;
        int u = v;
        for(int j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;
                tmp = dist[j];
            }
        s[u] = 1;
        
        for(int j=1; j<=n; ++j)
            if((!s[j]) && c[u][j]<maxint)
            {
                int newdist = dist[u] + c[u][j];
                if(newdist <= dist[j])
                {
                    if (newdist < dist[j]) {
                        _prev[j].clear();
                        dist[j] = newdist;
                    }
                    _prev[j].push_back(u);
                }
            }
    }
}

void searchPath(vector<int> *_prev, int v, int u, int sta[], int len) {
    if (u == v) {
        //cout<<v;
        return ;
    }
    sta[len] = u;
    for (int i = 0 ; i < _prev[u].size(); ++i ) {
        searchPath(_prev, v, _prev[u][i], sta, len + 1);
        net.addedge(_prev[u][i],u,gra[_prev[u][i]][u]);
        //cout << _prev[u][i] << " -> " << u;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t;cin >> t;
    while(t--){
        cin >> n >> line;
        for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) {
            c[i][j] = c[j][i] = maxint;
            gra[i][j] = gra[j][i] = -1;
        }
        for(int i = 1;i <= line;i++) {
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            c[x][y] = c[y][x] = 1;
            gra[x][y] = z;
            gra[y][x] = z;
        }
        for(int i = 1; i <= n;i++)
            dist[i] = maxint;
        Dijkstra(n, 1, dist, _prev, c);
        net.init(n);
        int sta[maxnum];
        searchPath(_prev, 1, n, sta, 0);
        
        printf("%d\n",net.dinic(1, n));
    }
    return 0;
}