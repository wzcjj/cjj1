//
//  main.cpp
//  3
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
#include <cstdio>
#include <ctime>
#include <bitset>
#include <functional>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 20005
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn];
int b[maxn];
vector<int>c[maxn];
queue<int>q;
void dfs(int x){
    b[x]--;
    if(b[x]==0)q.push(x);
    if(a[x]>=c[x].size())return;
    dfs(c[x][a[x]]);
    a[x]++;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    int I=0;
    while (N--) {
        I++;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)c[i].clear();
        for(i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            b[y]++;
            c[x].push_back(y);
        }
        int ans=0;
        for(i=0;i<n;i++)if(b[i]==0){
            q.push(i);
        }
        while(!q.empty()){
            i=q.front();
            q.pop();
            for(j=a[i];j<c[i].size();j++)dfs(c[i][j]);
            ans+=c[i].size()-a[i];
            a[i]=c[i].size();
        }
        printf("Case %d: %d\n",I,ans);
    }
    return 0;
}
