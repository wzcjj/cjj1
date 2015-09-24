//
//  main.cpp
//  32
//
//  Created by wzcjj on 15/8/26.
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
#define maxn 20005
#define P 1000000007
#define INF 2100000000
using namespace std;

int ans;
struct node{
    int y,z;
};
vector<node> a[maxn];
int dfs(int x,int ty,int fa){
    int u=0,d=0;
    for(int i=0;i<a[x].size();i++)if(a[x][i].y!=fa){
        if(a[x][i].z)d+=max(dfs(a[x][i].y,a[x][i].z,x),1);
        else u+=max(dfs(a[x][i].y,a[x][i].z,x),1);
    }
    int t=min(d,u);
    ans+=t;
    d-=t;
    u-=t;
    if(ty==1){
        ans+=u;
        return d;
    }
    else if(ty==0){
        ans+=d;
        return u;
    }
    else{
        return u+d;
    }
}
int main(int argc, const char * argv[]) {
    int i,n,N;
    cin>>N;
    int I=0;
    while (N--) {
        I++;
        scanf("%d",&n);
        for(i=0;i<n;i++)a[i].clear();
        for(i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            node t;
            t.y=y;
            t.z=1;
            a[x].push_back(t);
            t.y=x;
            t.z=0;
            a[y].push_back(t);
        }
        ans=0;
        ans+=dfs(0,-1,-1);
        printf("Case %d: %d\n",I,ans);
    }
    return 0;
}
