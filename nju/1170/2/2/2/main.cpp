//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/1/13.
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
#define maxn 205
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
#define node(x,y) ((x-1)*n+y)
using namespace std;

int a[maxn*maxn];
int d[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{2,-1},{2,1},{1,-2},{1,2}};
int val[5],n;
bool check(int x,int y){
    return x>0&&x<=n&&y>0&&y<=n&&a[node(x,y)]!=-1;
}
void dfs(int x,int y,int v){
    a[node(x,y)]=v;
    val[v]++;
    int cnt=0;
    for(int i=0;i<8;i++){
        if(check(x+d[i][0],y+d[i][1]))cnt++;
        if(check(x+d[i][0],y+d[i][1])&&a[node(x+d[i][0],y+d[i][1])]==0){
            dfs(x+d[i][0],y+d[i][1],3-v);
            val[v]+=max(val[5-v]-1,0);
            val[5-v]=0;
        }
    }
    if(cnt==1)val[v+2]++;
}
int main(int argc, const char * argv[]) {
    int i,j,m,N;
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    for(i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[node(x,y)]=-1;
    }
    int ans=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[node(i,j)]==0){
                val[1]=val[2]=val[3]=val[4]=0;
                dfs(i,j,1);
                ans+=max(val[1],val[2]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
