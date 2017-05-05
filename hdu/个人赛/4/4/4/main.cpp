//
//  main.cpp
//  4
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
#define maxn 105
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

int a[maxn][maxn];
struct node{
    int x,y,v;
    friend bool operator<(node x,node y){
        return x.v>y.v;
    }
};
node b[maxn*maxn];
int fa[maxn];
int getfa(int x){
    if(fa[x]!=x)fa[x]=getfa(fa[x]);
    return fa[x];
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d",&n)!=EOF) {
        for(i=1;i<=n;i++)fa[i]=i;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        m=0;
        for(i=1;i<n;i++){
            for(j=i+1;j<=n;j++){
                b[++m].v=a[i][j];
                b[m].x=i;
                b[m].y=j;
            }
        }
        int ans=0;
        sort(b+1,b+1+m);
        for(i=1;i<=m;i++){
            if(getfa(b[i].x)!=getfa(b[i].y)){
                fa[getfa(b[i].x)]=getfa(b[i].y);
                ans+=b[i].v;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
