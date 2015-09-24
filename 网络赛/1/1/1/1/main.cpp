//
//  main.cpp
//  1
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
#define maxn 150005
#define P 1000000007
#define INF 2100000000
using namespace std;

struct node {
    int t,v;
    friend bool operator<(node x,node y){
        if(x.v==y.v)return x.t>y.t;
        else return x.v<y.v;
    }
}a[maxn];
char na[maxn][205];
priority_queue<node>pq;
int ans[maxn];
struct node1{
    int t,p;
    friend bool operator<(node1 x,node1 y){
        return x.t<y.t;
    }
}door[maxn];
int que[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,q;
    cin>>N;
    while (N--) {
        scanf("%d%d%d",&n,&m,&q);
        while(!pq.empty())pq.pop();
        int now=0,sum=0;
        for(i=1;i<=n;i++){
            scanf("%s%d",na[i],&a[i].v);
            a[i].t=i;
        }
        for(i=1;i<=m;i++){
            scanf("%d%d",&door[i].t,&door[i].p);
        }
        int ma=0;
        for(i=1;i<=q;i++){
            scanf("%d",&que[i]);
            if(que[i]>ma)ma=que[i];
        }
        sort(door+1,door+1+m);
        door[++m].t=n;
        door[m].p=n;
        for(i=1;i<=m;i++){
            for(j=now+1;j<=door[i].t;j++){
                pq.push(a[j]);
            }
            now=door[i].t;
            for(j=1;j<=door[i].p&&!pq.empty();j++){
                node x=pq.top();
                pq.pop();
                ans[++sum]=x.t;
            }
            if(sum>ma)break;
        }
        for(i=1;i<=q;i++){
            if(i<q)printf("%s ",na[ans[que[i]]]);
            else printf("%s\n",na[ans[que[i]]]);
        }
    }
    return 0;
}
