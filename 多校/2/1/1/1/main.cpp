//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/7/21.
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

long long a[maxn];
long long cnt;
long long gcd(long long x,long long y){
    if(y==0)return x;
    return gcd(y,x%y);
}
int main(int argc, const char * argv[]) {
    int i,j,m,N;
    long long n;
    cin>>N;
    while (N--) {
        scanf("%lld",&n);
        long long sum1=0,sum2=0;
        cnt=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            a[i]=abs(a[i]);
            sum1+=a[i];
            sum2+=a[i]*a[i];
        }
        sum2*=n;
        long long gc=gcd(sum2-sum1*sum1,n);
        printf("%lld/%lld\n",(sum2-sum1*sum1)/gc,n/gc);
    }
    return 0;
}
