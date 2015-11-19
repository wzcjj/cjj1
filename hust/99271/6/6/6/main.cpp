//
//  main.cpp
//  6
//
//  Created by wzcjj on 15/11/11.
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
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;

struct node{
    int x,y,z;
};
node a[maxn];
inline void swap(int i,int j){
    node t;
    t=a[i];
    a[i]=a[j];
    a[j]=t;
}
int fa[maxn];
int getfa(int x){
    if(fa[x]!=x)fa[x]=getfa(fa[x]);
    return fa[x];
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    int I=0;
    while (N--) {
        I++;
        printf("Case #%d: ",I);
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        }
        j=m;
        for(i=1;i<j;i++){
            while(j>i&&a[j].z)j--;
            while(i<j&&!a[i].z)i++;
            swap(i,j);
        }
        int l=0,r=0;
        int sum=0;
        for(i=1;i<=n;i++)fa[i]=i;
        for(i=1;i<=m;i++){
            if(getfa(a[i].x)==getfa(a[i].y))continue;
            fa[getfa(a[i].x)]=getfa(a[i].y);
            l+=a[i].z;
            sum++;
        }
        for(i=1;i<=n;i++)fa[i]=i;
        for(i=m;i>=1;i--){
            if(getfa(a[i].x)==getfa(a[i].y))continue;
            fa[getfa(a[i].x)]=getfa(a[i].y);
            r+=a[i].z;
        }
        bool flag = false;
        int c=1,d=2;
        while(c<=r){
            int t=c+d;
            if(c<=r&&c>=l){
                flag=true;
                break;
            }
            c=d;
            d=t;
        }
        if(flag&&sum==n-1)puts("Yes");
        else puts("No");
    }
    return 0;
}
