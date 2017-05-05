//
//  main.cpp
//  12
//
//  Created by wzcjj on 16/8/9.
//  Copyright (c) 2016年 wzcjj. All rights reserved.
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
#define maxn 500005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct node{
    int x,y;
};
bool cmp(node a,node b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
bool cmp1(node a,node b){
    if(a.y==b.y)return a.x<b.x;
    return a.y<b.y;
}
node a[maxn];
int fa[maxn];
int getfa(int x){
    if(fa[x]!=x)fa[x]=getfa(fa[x]);
    return fa[x];
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (true) {
        scanf("%d",&n);
        if(n==0)break;
        for(i=1;i<=n;i++){
            fa[i]=i;
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        sort(a+1, a+1+n, cmp);
        for(i=1;i<=n;i=j){
            for(j=i+1;j<=n;j++){
                if(a[i].x==a[j].x){
                    fa[j]=i;
                }
                else {
                    break;
                }
            }
        }
        sort(a+1, a+1+n, cmp1);
        for(i=1;i<=n;i=j){
            for(j=i+1;j<=n;j++){
                if(a[i].y==a[j].y){
                    fa[j]=i;
                }
                else {
                    break;
                }
            }
        }
        int t=getfa(1);
        bool flag=0;
        for(i=2;i<=n;i++){
            if(getfa(i)!=t){
                flag=1;
                break;
            }
        }
        if(flag)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
