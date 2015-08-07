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
using namespace std;

vector<int> a[10005];
int color[10005];
int col[10005];
bool dp[10005];
void dfs(int x,int co){
    color[x]=co;
    col[co]++;
    for(int i=0;i<a[x].size();i++)if(color[a[x][i]]==0){
        dfs(a[x][i],-co);
    }
}
int main() {
    int i,j,N,m,n;
    cin>>N;
    while (N--) {
        cin>>n>>m;
        memset(color,0,sizeof(color));
        memset(col,0,sizeof(col));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        int t=0;
        for(i=1;i<=n;i++)if(color[i]==0){
            dfs(i,++t);
        }
        int minn=n;
        dp[0]=true;
        for(i=1;i<=t;i++){
            for(j=min(n-minn,n/2+1);j>=0;j--)if(dp[j]){
                dp[j+col[i]]=dp[j+col[-i]]=true;
            }
            minn=min(min(col[i],col[-i]),minn);
        }
        for(i=n/2;i>=0;i--)if(dp[i])break;
        int sum=0;
        cout<<i*(n-i)-m <<endl;
        
    }
    return 0;
}
