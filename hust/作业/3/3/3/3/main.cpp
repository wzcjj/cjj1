//
//  main.cpp
//  3
//
//  Created by wzcjj on 15/8/28.
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
#define maxn 105
#define P 1000000007
#define INF 2100000000
using namespace std;

struct node{
    int y,z;
};
vector<node> a[maxn];
bool vis[maxn];
int fl[maxn],ans;
void dfs(int x,int de){
    vis[x]=true;
    fl[x]=de;
    for(int i=0;i<a[x].size();i++){
        if(fl[a[x][i].y]){
            if(ans==-1||ans>fl[x]-fl[a[x][i].y]+a[x][i].z)ans=fl[x]-fl[a[x][i].y]+a[x][i].z;
        }
        if(!vis[a[x][i].y]){
            dfs(a[x][i].y,de+a[x][i].z);
        }
    }
    fl[x]=0;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n;
    for(scanf("%d",&n);n!=-1;scanf("%d",&n)) {
        scanf("%d",&m);
        for(i=1;i<=n;i++)a[i].clear();
        memset(vis,0,sizeof(vis));
        memset(fl, 0, sizeof(fl));
        ans=-1;
        for(i=1;i<=m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            node t;
            t.y=y;
            t.z=z;
            a[x].push_back(t);
        }
        for(i=1;i<=n;i++)if(!vis[i])dfs(1,1);
        if(ans==-1)puts("No solution.");
        else cout<<ans<<endl;
    }
    return 0;
}
