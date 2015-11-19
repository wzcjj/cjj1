//
//  main.cpp
//  2767
//
//  Created by wzcjj on 15/10/25.
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
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;

class Gragh{
public:
    vector<int> a[maxn];
    bool visit[maxn];
    int color[maxn];
    int flag[maxn];
    int fa[maxn];
    int father[maxn];
    
    int getfa(int x){
        if(fa[x] != x)fa[x] = getfa(fa[x]);
        return fa[x];
    }
    
    void init(int n){
        for(int i=1;i<=n;i++){
            a[i].clear();
            visit[i] = color[i] = flag[i] = 0;
            fa[i] = i;
        }
    }
    
    void addedge(int x,int y){
        a[x].push_back(y);
    }
    
    void tarjan(int x,int fat){     //强连通分量
        if(visit[x])return;
        visit[x] = flag[x] = true;
        father[x] = fat;
        for(int i = 0; i < a[x].size(); i ++){
            int y = a[x][i];
            if(visit[y]){
                if(flag[y]){
                    int j = x;
                    while(j != getfa(y)){
                        fa[getfa(j)] = getfa(y);
                        j = getfa(father[j]);
                    }
                }
            }
            else {
                tarjan(y, x);
            }
        }
        flag[x] = false;
    }
    
    int num(int n){      //强连通分量数
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            flag[i] = 0;
        }
        for(int i = 1; i <= n; i ++){
            if(!flag[getfa(i)]){
                ans ++;
                flag[getfa(i)] = 1;
            }
        }
        return ans;
    }
};
Gragh G;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (true) {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        G.init(n);
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            G.addedge(x, y);
        }
        for(i=1;i<=n;i++){
            G.tarjan(i, -1);
        }
        if(G.num(n) == 1)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
