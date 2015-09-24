//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/8/26.
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
#define maxn 20005
#define P 1000000007
#define INF 2100000000
using namespace std;

struct node{
    int x,y,v;
    friend bool operator<(node x,node y){
        return x.v>y.v;
    }
};
node a[5*maxn];
int b[maxn];
int fa[2*maxn];
int getfa(int x){
    if(x!=fa[x])fa[x]=getfa(fa[x]);
    return fa[x];
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
    }
    memset(b,0,sizeof(b));
    for(i=1;i<=2*n;i++)fa[i]=i;
    int ans=0,tmp=1;
    sort(a+1,a+1+m);
    for(i=1;i<=m;i++){
        if(b[a[i].x]==0&&b[a[i].y]==0){
            b[a[i].x]=tmp;
            b[a[i].y]=2*n+1-tmp;
            tmp++;
        }
        else if(b[a[i].x]==0){
            b[a[i].x]=2*n+1-getfa(b[a[i].y]);
        }
        else if(b[a[i].y]==0){
            b[a[i].y]=2*n+1-getfa(b[a[i].x]);
        }
        else{
            if(getfa(b[a[i].x])==getfa(b[a[i].y])){
                ans=a[i].v;
                break;
            }
            int t1=getfa(b[a[i].y]),t2=getfa(b[a[i].x]);
            fa[t1]=2*n+1-t2;
            fa[2*n+1-t1]=t2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
