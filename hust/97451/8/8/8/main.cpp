//
//  main.cpp
//  8
//
//  Created by wzcjj on 15/10/30.
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
#define maxn 10005
#define P 1000000007
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;

int a[maxn];
int ans[maxn];
int op[maxn];
void dfs(int n){
    int an=0;
    for(int i=0;i<=7;i++){
        a[1]=(i&4)>>2;
        a[2]=(i&2)>>1;
        a[3]=i&1;
        for(int j=4;j<=n;j++){
            a[j]=!(a[op[j]>>8]&&a[op[j]&255]);
        }
        an=(an<<1)+a[n];
    }
    if(ans[an]>=n-2)ans[an]=n-2;
    if(n>11)return;
    for(int i=1;i<=2;i++){
        for(int j=i;j<=2;j++){
            op[n+1]=(i<<8)+j;
            dfs(n+1);
        }
    }
    for(int i=1;i<=n;i++){
        //for(int j=i;j<=n;j++){
            op[n+1]=(i<<8)+n;
            dfs(n+1);
        //}
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,x;
    n=3;
    memset(ans,127,sizeof(ans));
    ans[85]=ans[51]=ans[15]=1;
    dfs(3);
    for(i=0;i<=255;i++){
        printf("ans[%d]=%d;\n",i,ans[i]);
    }
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
    }
    return 0;
}
