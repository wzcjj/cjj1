//
//  main.cpp
//  7
//
//  Created by wzcjj on 16/8/2.
//  Copyright (c) 2016年 wzcjj. All rights reserved.
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
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int flag[20];
long long a[maxn];
int check(long long x){
    memset(flag, 0, sizeof(flag));
    while(x){
        int y=x%10;
        if(flag[y])return 0;
        flag[y]=true;
        x/=10;
    }
    return 1;
}
int checkk(long long x,long long k){
    memset(flag, -1, sizeof(flag));
    int i=0;
    while(x){
        int y=x%10;
        for(int j=0;j<k-1;j++)if(flag[j]==y)return 0;
        flag[i%(k-1)]=y;
        x/=10;
        i++;
    }
    return 1;
}
long long pow(int x,int y){
    long long t=1;
    for(int i=1;i<=y;i++)t*=x;
    return t;
}
long long calc(long long x,long long k){
    if(x==1000000000000000000LL)return calc(x-1, k);
    if(x<pow(10,k))return a[x];
    long long t=1;
    while(t<=x)t*=10;
    long long ret=calc(t/10-1,k)+(calc(x/10, k)-calc(t/100-1, k))*(11-k);
    t=x%10;
    x/=10;
    for(long long i=x*10+t+1;i<=x*10+9;i++)ret-=checkk(i,k);
    return ret;
}
int main(int argc, const char * argv[]) {
    long long i,j,m,n=99999,N,k;
    a[0]=0;
    for(i=1;i<=n;i++)a[i]=a[i-1]+check(i);
    while (scanf("%lld%lld%lld",&m,&n,&k)!=EOF) {
        printf("%lld\n",calc(n, k)-calc(m-1, k));
    }
    return 0;
}
