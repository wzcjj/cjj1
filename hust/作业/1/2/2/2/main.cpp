//
//  main.cpp
//  2
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

int a[maxn],b[maxn],c[1000005];
void dfs(int l1,int r1,int l2,int r2){
    if(l2>r2)return;
    dfs(l1+1,l1+c[a[l1]]-l2,l2,c[a[l1]]-1);
    dfs(l1+c[a[l1]]-l2+1,r1,c[a[l1]]+1,r2);
    printf("%d\n",a[l1]);
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    n=0;
    while (scanf("%d",&a[++n])!=EOF);
    n--;
    for(i=1;i<=n;i++)b[i]=a[i];
    sort(b+1,b+1+n);
    for(i=1;i<=n;i++)c[b[i]]=i;
    dfs(1,n,1,n);
    return 0;
}
