//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/7/30.
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
#define maxn 1000005
#define P 1000000007
#define INF 2100000000
using namespace std;

long long a[maxn];
int b[maxn];
bool f[10];
int l,r;
int ans,now;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    for(i=1;i<=100000;i++)b[i]=a[i]+b[i-1];
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%lld",&a[i]);
        j=1;
        int ans=0;
        for(i=1;i<=n;i++){
            while(j<=n&&(j-i<=1||a[j]-a[j-1]==a[j-1]-a[j-2]))j++;
            if(ans<j-i)ans=j-i;
            j--;
        }
        j=1;
        int ans1=ans;
        ans=0;
        for(i=1;i<=n;i++){
            while(j<=n&&(j-i<=1||a[j]*a[j-2]==a[j-1]*a[j-1]))j++;
            if(ans<j-i)ans=j-i;
            j--;
        }
        if(ans1>ans)ans=ans1;
        printf("%d\n",ans);
    }
    return 0;
}
