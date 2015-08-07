//
//  main.cpp
//  1
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

long long a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    a[0]=2;
    for(i=1;i<=10000;i++)a[i]=a[i-1]*a[i-1]%P;
    while (N--) {
        scanf("%d",&n);
        n--;
        long long ans=1;
        for(i=0;n;i++)if((1<<i)&n){
            ans=ans*a[i]%P;
            n-=(1<<i);
        }
        ans--;
        printf("%lld\n",ans);
    }
    return 0;
}
