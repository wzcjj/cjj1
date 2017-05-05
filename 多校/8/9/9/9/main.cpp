//
//  main.cpp
//  9
//
//  Created by wzcjj on 16/8/11.
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
#define P 998244353
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

long long a[maxn];
long long b[maxn];
long long c[maxn];
bool cmp(int x,int y){
    return x>y;
}
int main(int argc, const char * argv[]) {
    int i,j,m=100000,n,N;
    b[0]=1;
    for(i=1;i<=m;i++)b[i]=b[i-1]*2%P;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        sort(a+1, a+1+n);
        for(i=1;i<=n;i++){
            a[i]=a[i]*b[i-1]%P;
        }
        long long sum=0;
        for(i=1;i<=n;i++){
            sum=(sum+a[i])%P;
        }
        c[1]=sum;
        for(i=2;i<=n;i++){
            c[i]=(c[i-1]+sum*(b[i-1]-1))%P;
            sum=(sum-a[n-i+2]+P)%P;
        }
        for(i=1;i<n;i++){
            printf("%lld ",c[i]);
        }
        printf("%lld\n",c[n]);
    }
    return 0;
}
