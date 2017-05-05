//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/3/3.
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
#define maxn 105
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

int a[maxn][maxn];
int ans[maxn];
int n;
void dfs(int x,int v){
    if(ans[x])return;
    ans[x]=v;
    for(int i=1;i<=n;i++)if(a[i][x])dfs(i,v);
}
int main(int argc, const char * argv[]) {
    int i,j;
    scanf("%d",&n);
    memset(ans,0,sizeof(ans));
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)a[i][i]=1;
    for(i=1;i<=n;i++)if(ans[i]==0){
        dfs(i,i);
    }
    for(i=1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
