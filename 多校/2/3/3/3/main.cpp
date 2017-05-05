//
//  main.cpp
//  3
//
//  Created by wzcjj on 16/7/21.
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
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

vector<int> a[maxn];
bool flag[maxn];
bool flag1[maxn];
queue<int>q;
int ans;
void dfs(int x,int fa,int deep){
    int z=0;
    flag[x]=true;
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa){
        if(!flag[a[x][i]]){
            dfs(a[x][i],x,deep+1);
            z=1;
        }
    }
    if(!z&&!flag1[x]&&deep>ans){
        q.push(x);
    }
    if(ans<deep)ans=deep;
    flag1[x]=true;
    flag[x]=false;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        memset(flag,0,sizeof(flag));
        memset(flag1,0,sizeof(flag1));
        ans=0;
        while(!q.empty())q.pop();
        q.push(1);
        flag1[1]=true;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            dfs(x,-1,0);
        }
        printf("%d\n",ans);
    }
    return 0;
}
