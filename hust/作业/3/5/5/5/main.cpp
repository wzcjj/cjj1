//
//  main.cpp
//  5
//
//  Created by wzcjj on 15/8/27.
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
#define maxn 1005
#define P 1000000007
#define INF 2100000000
using namespace std;

struct node{
    int y,z;
};
vector<node> a[maxn];
bool flag[maxn];
queue<int>b;
int c[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,p,q;
    while (scanf("%d%d%d",&m,&p,&q)!=EOF) {
        n=0;
        memset(flag,0,sizeof(flag));
        memset(c, -1, sizeof(c));
        for(i=0;i<=1001;i++)a[i].clear();
        for(i=1;i<=m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(x>n)n=x;
            if(y>n)n=y;
            node t;
            t.y=y;
            t.z=z;
            a[x].push_back(t);
            t.y=x;
            a[y].push_back(t);
        }
        for(i=1;i<=p;i++){
            scanf("%d",&j);
            node t;
            t.y=j;
            t.z=0;
            a[0].push_back(t);
        }
        for(i=1;i<=q;i++){
            scanf("%d",&j);
            node t;
            t.y=n+1;
            t.z=0;
            a[j].push_back(t);
        }
        b.push(0);
        c[0]=0;
        while(!b.empty()){
            int x=b.front();
            flag[x]=false;
            b.pop();
            for(i=0;i<a[x].size();i++){
                if(c[a[x][i].y]==-1||c[a[x][i].y]>c[x]+a[x][i].z){
                    c[a[x][i].y]=c[x]+a[x][i].z;
                    if(!flag[a[x][i].y]){
                        b.push(a[x][i].y);
                        flag[a[x][i].y]=true;
                    }
                }
            }
        }
        printf("%d\n",c[n+1]);
    }
    return 0;
}
