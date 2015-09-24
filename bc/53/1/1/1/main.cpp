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
vector<int> a[maxn];
bool dfs(int x,int fa){
    int cnt=0,sum=0;
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa){
        cnt++;
        sum+=dfs(a[x][i],x);
    }
    if(cnt>1&&cnt!=sum)ans=false;
    if(cnt==0)return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d",&n)!=EOF) {
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        ans=true;
        dfs(1,-1);
        if(ans)puts("YES");
        else puts("NO");
    }
    return 0;
}
