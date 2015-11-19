//
//  main.cpp
//  5
//
//  Created by wzcjj on 15/11/19.
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
#define maxn 205
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

int a[maxn],b[maxn];
struct edge{
    int x,y,z;
    friend bool operator<(edge x,edge y){
        return x.z<y.z;
    }
};
edge c[maxn*maxn];
int fa[maxn];
int sum;
int getfa(int x){
    if(x!=fa[x]){
        fa[x]=getfa(fa[x]);
        a[fa[x]]+=a[x];
        a[x]=0;
        b[fa[x]]+=b[x];
        b[x]=0;
        int t=min(a[fa[x]], b[fa[x]]);
        a[fa[x]]-=t;
        b[fa[x]]-=t;
        sum-=t;
    }
    return fa[x];
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (true) {
        scanf("%d",&n);
        sum=0;
        if(n==0)break;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)scanf("%d",&b[i]);
        for(i=1;i<=n;i++){
            int t=min(a[i], b[i]);
            a[i]-=t;
            b[i]-=t;
        }
        for(i=1;i<=n;i++)sum+=a[i];
        for(i=1;i<=n;i++)fa[i]=i;
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].z);
        }
        sort(c+1,c+m+1);
        if(sum==0){
            printf("0\n");
            continue;
        }
        for(i=1;i<=m;i++){
            if(getfa(c[i].x)==getfa(c[i].y))continue;
            fa[getfa(c[i].x)]=getfa(c[i].y);
            getfa(c[i].x);
            if(sum==0)break;
        }
        if(i==m+1)printf("No Solution\n");
        else printf("%d\n",c[i].z);
    }
    return 0;
}
