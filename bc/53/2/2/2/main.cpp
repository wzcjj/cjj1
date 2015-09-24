//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/8/29.
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
#define maxn 10005
#define P 1000000007
#define INF 2100000000
using namespace std;

bool ans;
int n;
vector<int> a[maxn];
bool fl[maxn];
void dfs(int x,int fa,int cnt){
    fl[x]=true;
    if(cnt==n){
        ans=true;
        return;
    }
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa&&!fl[a[x][i]]){
        dfs(a[x][i],x,cnt+1);
        if(ans)return;
    }
    fl[x]=false;
}
int main(int argc, const char * argv[]) {
    int i;
    while (scanf("%d",&n)!=EOF) {
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<=n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        ans=false;
        int flag=0;
        memset(fl,0,sizeof(fl));
        for(i=1;i<=n;i++)if(a[i].size()==1&&!ans&&flag<=1){
            dfs(i,-1,1);
            flag++;
        }
        if(!flag)dfs(1,-1,1);
        if(ans)puts("YES");
        else puts("NO");
    }
    return 0;
}
