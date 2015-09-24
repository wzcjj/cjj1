//
//  main.cpp
//  2
//
//  Created by wzcjj on 15/8/25.
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
#include <ctime>
#include <bitset>
#include <functional>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 2005
#define P 1000000007
#define INF 2100000000
using namespace std;

vector<int> a[maxn];
bool vis[maxn];
int flag[maxn];
bool ans;
int n;
void dfs(int x,int fl){
    vis[x]=true;
    flag[x]=fl;
    for(int i=0;i<a[x].size();i++){
        if(flag[a[x][i]]&&flag[2*n+1-a[x][i]]&&flag[a[x][i]]<flag[2*n+1-a[x][i]]){
            ans=true;
            return;
        }
        if(!vis[a[x][i]]){
            dfs(a[x][i],fl+1);
            if(ans)return;
        }
    }
    flag[x]=0;
}
int main(int argc, const char * argv[]) {
    int i,j,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        int x,y,z;
        char c[5];
        scanf("%d%d%d%s",&x,&y,&z,c);
        if(c[0]=='A'){
            if(z){
                a[2*n+1-x].push_back(2*n+1-y);
                a[2*n+1-y].push_back(2*n+1-x);
                a[x].push_back(2*n+1-x);
                a[y].push_back(2*n+1-y);
            }
            else{
                a[2*n+1-x].push_back(y);
                a[2*n+1-y].push_back(x);
            }
        }
        else if(c[0]=='X'){
            if(z){
                a[x].push_back(2*n+1-y);
                a[y].push_back(2*n+1-x);
                a[2*n+1-x].push_back(y);
                a[2*n+1-y].push_back(x);
            }
            else{
                a[x].push_back(y);
                a[y].push_back(x);
                a[2*n+1-x].push_back(2*n+1-y);
                a[2*n+1-y].push_back(2*n+1-x);
            }
        }
        else{
            if(z){
                a[x].push_back(2*n+1-y);
                a[y].push_back(2*n+1-x);
            }
            else{
                a[2*n+1-x].push_back(x);
                a[2*n+1-y].push_back(y);
                a[x].push_back(y);
                a[y].push_back(x);
            }
        }
    }
    memset(flag,0,sizeof(flag));
    memset(vis,0,sizeof(vis));
    ans=false;
    vis[n]=vis[n+1]=true;
    for(i=0;i<=2*n+1;i++)if(!vis[i]){
        dfs(i,1);
        if(ans)break;
    }
    if(ans)puts("NO");
    else puts("YES");
    return 0;
}
