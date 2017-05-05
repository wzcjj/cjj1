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
int d[4][2]={{0,-1},{0,1},{-1,0},{1,0}};//方向
struct sqr{
    int a[3][3];
    int deep;
};
queue<sqr> q;//状态队列

bool check(int x,int y){
    return x>=0&&x<3&&y>=0&&y<3;
}

void swap(int &x,int &y){
    int t=x;
    x=y;
    y=t;
}

int bfs(){
    int i,j,k;
    
    while(!q.empty()){
        sqr sq=q.front();
        q.pop();
        
        //判断是否到达目标
        bool flag = false;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(sq.a[i][j]!=t[i][j]){
                    flag = true;
                }
            }
        }
        if(!flag)return sq.deep;
        
        //移动
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(sq.a[i][j]==0){
                    for(k=0;k<4;k++){
                        int x1=i,y1=j,x2=i+d[k][0],y2=j+d[k][1];
                        if(!check(x2,y2))continue;
                        swap(sq.a[x1][y1],sq.a[x2][y2]);
                        sq.deep++;
                        q.push(sq);
                        swap(sq.a[x1][y1],sq.a[x2][y2]);
                        sq.deep--;
                    }
                }
            }
        }
    }
    
    return INF;
}

int main(int argc, const char * argv[]) {
    int i,j,m,n,k;
    
    //读入
    sqr sq;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&s[i][j]);
            sq.a[i][j]=s[i][j];
        }
    }
    sq.deep = 0;
    q.push(sq);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&t[i][j]);
        }
    }
    
    printf("%d\n",bfs());
    return 0;
}
