//
//  main.cpp
//  72
//
//  Created by wzcjj on 15/10/20.
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
#define maxn 100005
#define P 1000000007
#define INF 2100000000000000LL
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;

struct edge{
    int x,y;
    long long z;
    friend bool operator<(edge x,edge y) {
        return x.z<y.z;
    }
}a[maxn];
long long d[maxn];
struct node{
    int i;
    long long v;
};
queue<node>q;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)d[i]=INF;
        while(!q.empty())q.pop();
        d[1]=0;
        for(i=1;i<=m;i++)scanf("%d%d%lld",&a[2*i].x,&a[2*i].y,&a[2*i].z);
        for(i=1;i<=m;i++){
            a[2*i-1].x=a[2*i].y;
            a[2*i-1].y=a[2*i].x;
            a[2*i-1].z=a[2*i].z;
        }
        sort(a+1, a+1+m*2);
        a[2*m+1].z=INF;
        for(i=1;i<=2*m;i++){
            if(d[a[i].y]>d[a[i].x]+a[i].z){
                node t;
                t.v=d[a[i].x]+a[i].z;
                t.i=a[i].y;
                q.push(t);
            }
            if(a[i].z!=a[i+1].z)while(!q.empty()){
                node x=q.front();
                q.pop();
                d[x.i]=min(d[x.i], x.v);
            }
        }
        if(d[n]==INF)printf("No answer\n");
        else printf("%lld\n",d[n]);
    }
    return 0;
}
