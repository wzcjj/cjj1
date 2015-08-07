//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/7/30.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define maxn 1005
using namespace std;

int a[maxn][maxn];
int m,n;
bool f[maxn][maxn];
struct node{
    int x,y;
};
int t1;
void dfs(){
    queue<node> q;
    int x,y;
    node t;
    t.x=t.y=1;
    q.push(t);
    while(!q.empty()){
        t=q.front();
        q.pop();
        x=t.x;
        y=t.y;
        if(x>1&&!f[x-1][y]){
            f[x-1][y]=true;
            t.x=x-1;
            t.y=y;
            if(a[x-1][y]==0)q.push(t);
            else if(t1<t.x+t.y-1)t1=t.x+t.y-1;
        }
        if(y>1&&!f[x][y-1]){
            f[x][y-1]=true;
            t.x=x;
            t.y=y-1;
            if(a[x][y-1]==0)q.push(t);
            else if(t1<t.x+t.y-1)t1=t.x+t.y-1;
        }
        if(x<n&&!f[x+1][y]){
            f[x+1][y]=true;
            t.x=x+1;
            t.y=y;
            if(a[x+1][y]==0)q.push(t);
            else if(t1<t.x+t.y-1)t1=t.x+t.y-1;
        }
        if(y<m&&!f[x][y+1]){
            f[x][y+1]=true;
            t.x=x;
            t.y=y+1;
            if(a[x][y+1]==0)q.push(t);
            else if(t1<t.x+t.y-1)t1=t.x+t.y-1;
        }
    }
}
int main(int argc, const char * argv[]) {
    int i,j,N;
    scanf("%d",&N);
    while (N--) {
        scanf("%d%d",&n,&m);
        char c;
        memset(f,0,sizeof(f));
        for(i=1;i<=n;i++){
            char str[maxn*2+1];
            scanf("%s",str);
            for(j=0;j<m;j++){
                a[i][j+1] = str[j]-'0';
            }
        }
        if(n==1&&m==1){
            printf("%d\n",a[1][1]);
            continue;
        }
        t1=0;
        f[1][1]=true;
        if(a[1][1]==1)t1=1;
        else {
            dfs();
        }
        if(f[n][m]||t1==0){
            printf("%d\n",a[n][m]);
            continue;
        }
        printf("1");
        for(i=t1;i<m+n-1;i++){
            bool flag =false;
            for(j=max(1,i-n+1);j<=min(i,m);j++)if(f[i-j+1][j]){
                if(i-j+1<n&&a[i-j+2][j]==0){
                    flag=true;
                    f[i-j+2][j]=true;
                }
                if(j<m&&a[i-j+1][j+1]==0){
                    flag=true;
                    f[i-j+1][j+1]=true;
                }
            }
            if(flag){
                printf("0");
                continue;
            }
            for(j=max(1,i-n+1);j<=min(i,m);j++)if(f[i-j+1][j]){
                f[i-j+2][j]=true;
                f[i-j+1][j+1]=true;
            }
            printf("1");
        }
        printf("\n");
    }
    return 0;
}
