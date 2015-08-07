//
//  main.cpp
//  bc48.52
//
//  Created by wzcjj on 15/7/25.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

struct node{
    int x,y;
    friend bool operator<(node x,node y){
        if(x.x<y.x)return true;
        else if(x.x>y.x)return false;
        else return x.y<y.y;
    }
};
vector<int> a[100005];
set<node> b[100005];
int c[100005],ans,n,m;

void dfs(int x,int fa){
    node t;
    t.x=t.y=c[x];
    b[x].insert(t);
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa ){
        dfs(a[x][i],x);
        for(set<node>::iterator it=b[a[x][i]].begin();it!=b[a[x][i]].end();it++){
            t=(*it);
            t.x=min(t.x,c[x]);
            t.y=max(t.y,c[x]);
            if(t.y-t.x<=m)b[x].insert(t);
        }
    }
}
int main() {
    int i,j,N;
    cin>>N;
    while (N--) {
        cin>>n>>m;
        ans=0;
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<=n;i++)b[i].clear();
        for(i=1;i<n;i++)scanf("%d",&c[i]);
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        dfs(1,-1);
        cout<<ans<<endl;
        
    }
    return 0;
}
