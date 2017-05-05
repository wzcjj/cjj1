//
//  main.cpp
//  6
//
//  Created by wzcjj on 16/10/6.
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
#define maxn 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

vector<int> a[maxn],b[maxn],c[maxn];
int ans[maxn];
void dfs(int x,int fa){
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa){
        dfs(a[x][i],x);
    }
    for(int i=0;i<b[x].size();i++){
        int cnt=0;
        for(int j=0;j<a[x].size();j++)if(a[x][j]!=fa){
            int y=a[x][j];
            if(b[y].size()==0)cnt++;
            else {
                int l=0,r=b[y].size();
                while (l<r-1) {
                    int mid=(l+r)>>1;
                    if(b[y][mid]<=b[x][i])l=mid;
                    else r=mid;
                }
                if(b[y][l]!=b[x][i]||c[y][l])cnt++;
            }
            if(cnt>=2)break;
        }
        if(cnt)c[x].push_back(1);
        else c[x].push_back(0);
        if(cnt<=1)ans[b[x][i]]++;
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I=0;
    cin>>N;
    while (N--) {
        I++;
        printf("Case #%d:\n",I);
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<=n;i++)b[i].clear();
        for(i=1;i<=n;i++)c[i].clear();
        memset(ans, 0, sizeof(ans));
        for(i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d",&x);
            for(j=1;j<=x;j++){
                scanf("%d",&y);
                b[y].push_back(i);
            }
        }
        dfs(1,-1);
        for(i=1;i<=m;i++){
            printf("%d\n",n-ans[i]);
        }
    }
    return 0;
}
