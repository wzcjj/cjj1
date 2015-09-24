//
//  main.cpp
//  6
//
//  Created by wzcjj on 15/8/21.
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
#define maxn 10005
#define P 1000000007
#define INF 2100000000
using namespace std;

struct node{
    int x,y;
    friend bool operator<(node x,node y){
        if(x.x==y.x)return x.y<y.y;
        else return x.x<y.x;
    }
};
set<node>b;
node a[maxn];
void asd(int l,int r){
    if(l>=r)return;
    int mid=(l+r)>>1;
    for(int i=l;i<=r;i++){
        node t;
        t.x=a[mid].x;
        t.y=a[i].y;
        b.insert(t);
    }
    asd(l,mid-1);
    asd(mid+1,r);
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        b.insert(a[i]);
    }
    sort(a+1,a+n+1);
    asd(1,n);
    printf("%d\n",b.size());
    for(set<node>::iterator it=b.begin();it!=b.end();it++)printf("%d %d\n",(*it).x,(*it).y);
    return 0;
}
