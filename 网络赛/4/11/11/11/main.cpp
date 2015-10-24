//
//  main.cpp
//  11
//
//  Created by wzcjj on 15/9/26.
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
#define maxn 200005
#define P 1000000007
#define INF 2100000000
using namespace std;

int d[maxn];
bool flag[maxn];
long long e[100];
int n;

long long pow1(long long x,long long y){
    long long ans=1;
    e[0]=x;
    for(int i=1;(1LL<<i)<=y;i++){
        e[i]=e[i-1]*e[i-1]%n;
    }
    for(int i=0;(1LL<<i)<=y;i++)if((1LL<<i)&y){
        ans=ans*e[i]%n;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    long long i,j,a,b,c;
    int I=0;
    while (scanf("%d%lld%lld%lld",&n,&a,&b,&c)!=EOF) {
        I++;
        memset(flag,0,sizeof(flag));
        printf("Case #%d:\n",I);
        for(i=1;i<n;i++){
            long long x=pow1(i,a+b);
            x=x%n;
            d[i]=n-x;
            if(x==0)flag[i]=true;
        }
        for(i=2;i<=2;i++){
            for(j=1;j<n;j++)if(!flag[j]){
                long long x=pow1(j,a*i+b);
                x+=pow1(d[j],c*(i-1)+1);
                x=x%n;
                if(x){
                    flag[j]=true;
                }
            }
        }
        bool fl=false;
        for(i=1;i<n;i++)if(!flag[i]){
            fl=true;
            printf("%d %d\n",i,d[i]);
        }
        if(!fl)printf("-1\n");
    }
    return 0;
}
