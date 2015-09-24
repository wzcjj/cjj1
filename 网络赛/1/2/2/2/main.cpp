//
//  main.cpp
//  2
//
//  Created by wzcjj on 15/9/13.
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

int v[maxn];
vector<int>a[maxn*10];
bool flag[maxn],vi[maxn];
queue<int>q;
int si[maxn];
void dfs(int x,long long &sum,long long &num){
    flag[x]=true;
    sum+=v[x];
    num++;
    for(int i=0;i<a[x].size();i++)if(!vi[a[x][i]]&&!flag[a[x][i]]){
        dfs(a[x][i],sum,num);
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<=n;i++)scanf("%d",&v[i]);
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        memset(vi,0,sizeof(vi));
        memset(flag, 0, sizeof(flag));
        for(i=1;i<=n;i++){
            si[i]=a[i].size();
            if(a[i].size()<=1){
                q.push(i);
                vi[i]=true;
            }
        }
        while(!q.empty()) {
            int x=q.front();
            q.pop();
            for(i=0;i<a[x].size();i++)if(!vi[a[x][i]]){
                si[a[x][i]]--;
                if(si[a[x][i]]<=1){
                    flag[a[x][i]]=true;
                    vi[a[x][i]]=true;
                    q.push(a[x][i]);
                }
            }
        }
        long long ans=0;
        for(i=1;i<=n;i++)if(!vi[i]&&!flag[i]){
            long long sum=0,num=0;
            dfs(i,sum,num);
            if(num&1)ans+=sum;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
