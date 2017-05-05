//
//  main.cpp
//  7
//
//  Created by wzcjj on 15/12/26.
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
#define maxn 30
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

#define ha 20

int a[maxn];
struct node{
    int x,v;
};
vector<node> ans[1<<ha];
int n,m;
short find(int x){
    for(int i=0;i<ans[x&((1<<ha)-1)].size();i++){
        if(ans[x&((1<<ha)-1)][i].x==x){
            return ans[x&((1<<ha)-1)][i].v;
        }
    }
    return -1;
}
int dfs(int x,int de){
    if(find(x)!=-1)return find(x);
    int maxx=0;
    if(!(de&1))maxx=INF;
    for(int i=0;i<n*m;i++){
        if(x&(1<<i)){
            int cnt=0;
            cnt+=((i+1)%m==0)||((x&(1<<(i+1)))==0);
            cnt+=((i)%m==0)||((x&(1<<(i-1)))==0);
            cnt+=(i+m>=m*n)||((x&(1<<(i+m)))==0);
            cnt+=(i-m<0)||((x&(1<<(i-m)))==0);
            if(cnt>=2){
                if(de&1)maxx=max(maxx,dfs(x^(1<<i),de+1)+a[i]);
                else maxx=min(maxx,dfs(x^(1<<i),de+1));
            }
        }
    }
    node t;
    t.x=x;
    t.v=maxx;
    ans[x&((1<<ha)-1)].push_back(t);
    return maxx;
}
int main(int argc, const char * argv[]) {
    int i,j,N;
    cin>>N;
    while (N--) {
        for(i=0;i<(1<<ha);i++)ans[i].clear();
        node t;
        t.x=0;
        t.v=0;
        ans[0].push_back(t);
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",&a[i*m+j]);
        int ans=dfs((1<<(n*m))-1,1);
        printf("%d\n",ans);
    }
    return 0;
}
