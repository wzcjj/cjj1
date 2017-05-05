//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/4/15.
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
#define maxn 15
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

int a[maxn][maxn];
bool flag[30];
int ans;
struct node{
    int x[70],y[70];
    friend bool operator<(node x,node y){
        for(int i=1;i<=ans;i++){
            if(x.x[i]==y.x[i]){
                if(x.y[i]==y.y[i])continue;
                return x.y[i]<y.y[i];
            }
            return x.x[i]<y.x[i];
        }
        return true;
    }
};
vector<node>b;
node t;
int n=8;
bool check(int x,int y){
    if(x>=n||x<0||y>=n||y<0)return false;
    if(flag[a[x][y]])return false;
    return true;
}
void dfs(int x,int y,int deep){
    flag[a[x][y]]=true;
    t.x[deep]=x;
    t.y[deep]=y;
    if(ans<deep){
        ans=deep;
        b.clear();
        b.push_back(t);
    }
    else if(ans==deep){
        b.push_back(t);
    }
    if(check(x-1,y))dfs(x-1,y,deep+1);
    if(check(x+1,y))dfs(x+1,y,deep+1);
    if(check(x,y-1))dfs(x,y-1,deep+1);
    if(check(x,y+1))dfs(x,y+1,deep+1);
    flag[a[x][y]]=false;
}
int main(int argc, const char * argv[]) {
    int i,j,N;
    cin>>N;
    while (N--) {
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)scanf("%d",&a[i][j]);
        }
        int x,y;
        scanf("%d%d",&x,&y);
        memset(flag,0,sizeof(flag));
        ans=0;
        b.clear();
        dfs(x,y,1);
        for(i=0;i<b.size();i++){
            for(j=i+1;j<b.size();j++){
                if(b[j]<b[i]){
                    t=b[i];
                    b[i]=b[j];
                    b[j]=t;
                }
            }
        }
        printf("%d\n",ans);
        for(i=0;i<b.size();i++){
            for(j=1;j<ans;j++){
                printf("%d:%d ",b[i].x[j],b[i].y[j]);
            }
            printf("%d:%d\n",b[i].x[ans],b[i].y[ans]);
        }
    }
    return 0;
}
