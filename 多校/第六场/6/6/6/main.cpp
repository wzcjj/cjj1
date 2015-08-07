//
//  main.cpp
//  6
//
//  Created by wzcjj on 15/8/6.
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

int a[maxn];
long long b[maxn];
long long c[70];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        memset(c, 0, sizeof(c));
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        b[0]=0;
        for(i=1;i<=n;i++)b[i]=b[i-1]+a[i];
        for(i=1;(1LL<<(i-1))<=max(b[n]-b[0],1LL);i++){
            long long l=1,r=1;
            for(r=1;r<=n;r++){
                while(b[r]-b[l-1]>=(1LL<<i))l++;
                c[i]+=r*(r-l+1)+(r+l)*(r-l+1)/2;
            }
        }
        int t=i-1;
        long long ans=0;
        for(i=t;i>=2;i--)c[i]-=c[i-1];
        for(i=1;i<=t;i++)ans+=c[i]*i;
        printf("%lld\n",ans);
    }
    return 0;
}
