//
//  main.cpp
//  9
//
//  Created by wzcjj on 15/8/6.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 200005
#define P 1000000007
#define INF 2100000000
using namespace std;


int l1[maxn],r1[maxn],c[maxn],ne[maxn],l2[maxn],r2[maxn],l[maxn],r[maxn];
long long ans[maxn];
bool flag[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    scanf("%d",&N);
    queue<int> q;
    memset(flag, 0, sizeof(flag));
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&l[i]);
        for(i=1;i<=n;i++)scanf("%d",&r[i]);
        for(i=1;i<=n;i++)scanf("%d",&c[i]);
        for(i=1;i<=n;i++){
            l1[i]=i-r[i];
            r1[i]=i-l[i];
            l2[i]=i+l[i];
            r2[i]=i+r[i];
        }
        for(i=1;i<=n;i++)ans[i]=-1;
        for(i=1;i<=n;i++)ne[i]=i;
        ans[1]=0;
        q.push(1);
        flag[1]=true;
        while (!q.empty()) {
            int x=q.front();
            q.pop();
            flag[x]=false;
            for(i=max(l1[x],1);i<=r1[x];i++){
                if(ans[i]==-1||ans[i]>ans[x]+c[x]){
                    ans[i]=ans[x]+c[x];
                    ne[i]=r1[x];
                    if(!flag[i]){
                        flag[i]=true;
                        q.push(i);
                    }
                }
                else{
                    i=ne[i];
                }
            }
            for(i=l2[x];i<=min(r2[x],n);i++){
                if(ans[i]==-1||ans[i]>ans[x]+c[x]){
                    ans[i]=ans[x]+c[x];
                    ne[i]=r2[x];
                    if(!flag[i]){
                        flag[i]=true;
                        q.push(i);
                    }
                }
                else{
                    i=ne[i];
                }
            }
        }
        for(i=1;i<n;i++){
            printf("%lld ",ans[i]);
        }
        printf("%lld\n",ans[n]);
    }
    return 0;
}
