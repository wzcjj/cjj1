//
//  main.cpp
//  3
//
//  Created by wzcjj on 15/8/18.
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
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;

long long a[maxn],ans[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    memset(a,-1,sizeof(a));
    ans[1]=0;
    for(i=2;i<=100000;i++){
        a[i]=i;
        for(j=2;j*i<=100000;j++)if(a[i*j]==-1)a[i*j]=j;
    }
    for(i=2;i<=100000;i++)ans[i]=ans[i-1]+a[i];
    for(i=1;i<=100000;i++)cout<<i<<' '<<ans[i]<<endl;
    while (scanf("%d",&n)!=EOF) {
        long long sum=0;
        for(i=1;(1<<i)<=n;i++)sum+=(1<<(i-1));
        printf("%lld\n",ans[n]-sum);
    }
    return 0;
}
