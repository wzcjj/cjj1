//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/8/22.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 20
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn][maxn],n,ans,p,q;
bool vis[maxn];
void dfs(int x,int sum){
    int min=INF,min1=-1;
    for(int i=1;i<=n;i++)if(i!=x&&!vis[i]){
        if(a[x][i]<min){
            min=a[x][i];
            min1=i;
        }
    }
    if(min1==-1){
        if(sum+a[x][q]<ans)ans=sum+a[x][q];
    }
    else{
        vis[min1]=true;
        dfs(min1,sum+a[x][min1]);
        vis[min1]=false;
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,N,k;
    cin>>N;
    memset(vis,0,sizeof(vis));
    while (N--) {
        scanf("%d%d",&n,&m);
        memset(a,-1,sizeof(a));
        for(i=1;i<=m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(a[x][y]==-1||a[x][y]>z){
                a[x][y]=a[y][x]=z;
            }
        }
        for(k=1;k<=n;k++){
            a[k][k]=0;
            for(i=1;i<=n;i++)if(a[i][k]!=-1){
                for(j=1;j<=n;j++)if(a[k][j]!=-1){
                    if(a[i][j]==-1||a[i][j]>a[i][k]+a[k][j])a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
        ans=INF;
        for(p=1;p<=n;p++){
            for(q=1;q<=n;q++){
                vis[1]=true;
                vis[p]=vis[q]=true;
                dfs(p,a[1][p]+a[1][q]);
                vis[p]=vis[q]=false;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
