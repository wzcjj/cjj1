//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/8/9.
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

long long gcd(long long x,long long y){
    if(y==0)return x;
    return gcd(y,x%y);
}
int main(int argc, const char * argv[]) {
    int i,j,N,n,m;
    long long x,y;
    while (true) {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        x=n;
        y=m;
        x=x*(m-1);
        y=y*m;
        long long t=gcd(x,y);
        x/=t;
        y/=t;
        printf("%lld/%lld\n",x,y);
    }
    return 0;
}
