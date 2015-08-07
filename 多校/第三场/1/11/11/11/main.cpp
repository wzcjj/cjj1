//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/7/28.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int a[105];
bool c[105];
vector<int> b[105];
void dfs(int x){
    for(int i=0;i<b[x].size();i++){
        a[x]++;
        dfs(b[x][i]);
        a[x]+=a[b[x][i]];
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(i=1;i<=n;i++)b[i].clear();
        int x,y;
        for(i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            b[x].push_back(y);
            c[y]=true;
        }
        int ans=0;
        for(i=1;i<=n;i++)if(!c[i])dfs(i);
        for(i=1;i<=n;i++)if(a[i]==m)ans++;
        printf("%d\n",ans);
    }
    //std::cout << "Hello, World!\n";
    return 0;
}
