//
//  main.cpp
//  dfs
//
//  Created by wzcjj on 16/4/1.
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
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

int s[3][3],t[3][3];//记录起始和终止状态
int a[3][3];//记录当前状态
int d[4][2]={{0,-1},{0,1},{-1,0},{1,0}};//方向
int ans=0;

bool check(int x,int y){
    return x>=0&&x<3&&y>=0&&y<3;
}

void swap(int &x,int &y){
    int t=x;
    x=y;
    y=t;
}

void dfs(int deep){
    int i,j,k;
    
    //判断是否到达目标
    bool flag = false;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]!=t[i][j]){
                flag = true;
            }
        }
    }
    if(!flag&&ans>deep)ans=deep;
    if(deep>=ans)return;
    
    //移动
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]==0){
                for(k=0;k<4;k++){
                    int x1=i,y1=j,x2=i+d[k][0],y2=j+d[k][1];
                    if(!check(x2,y2))continue;
                    swap(a[x1][y1],a[x2][y2]);
                    dfs(deep+1);
                    swap(a[x1][y1],a[x2][y2]);
                }
                return;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int i,j,m,n,k;
    
    //读入
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&s[i][j]);
            a[i][j]=s[i][j];
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&t[i][j]);
        }
    }
    
    //估算答案
    for(k=1;k<9;k++){
        int x1,y1,x2,y2;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(s[i][j]==k){
                    x1=i;
                    y1=j;
                }
            }
        }
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(t[i][j]==k){
                    x2=i;
                    y2=j;
                }
            }
        }
        ans+=abs(x1-x2)+abs(y1-y2);
    }
    
    dfs(0);
    
    printf("%d\n",ans);
    return 0;
}

