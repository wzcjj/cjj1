//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/9/24.
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
using namespace std;

int a[maxn][maxn],ans[maxn][maxn],c[maxn][maxn],n;
int b[1005];
void fl(int x[maxn][maxn],int y[maxn][maxn],int z[maxn][maxn]){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(x[i][j]>y[i][k]+z[k][j])x[i][j]=y[i][k]+z[k][j];
            }
        }
    }
}
void co(int x[maxn][maxn],int y[maxn][maxn]){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            x[i][j]=y[i][j];
            y[i][j]=INF;
        }
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,s,e;
    while (scanf("%d%d%d%d",&m,&n,&s,&e)!=EOF) {
        int t=0;
        for(i=1;i<=200;i++){
            for(j=1;j<=200;j++)a[i][j]=c[i][j]=ans[i][j]=INF;
            ans[i][i]=0;
        }
        memset(b,0,sizeof(b));
        for(i=1;i<=n;i++){
            int x,y,z;
            scanf("%d%d%d",&z,&x,&y);
            if(b[x]==0)b[x]=++t;
            if(b[y]==0)b[y]=++t;
            if(a[b[x]][b[y]]>z){
                a[b[x]][b[y]]=z;
                a[b[y]][b[x]]=z;
            }
        }
        n=t;
        s=b[s];
        e=b[e];
        while(m){
            if(m&1){
                fl(c,ans,a);
                co(ans,c);
            }
            fl(c,a,a);
            co(a,c);
            m>>=1;
        }
        printf("%d\n",ans[s][e]);
    }
    return 0;
}
