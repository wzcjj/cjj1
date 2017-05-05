//
//  main.cpp
//  tongji
//
//  Created by wzcjj on 16/6/22.
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
#define maxn 10005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

double a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    N=1;
    while (1) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%lf",&a[i]);
        }
        double ex=0,s=0;
        for(i=1;i<=n;i++){
            ex+=a[i];
        }
        ex/=n;
        for(i=1;i<=n;i++){
            s+=(a[i]-ex)*(a[i]-ex);
        }
        s/=n-1;
        s=sqrt(s);
        printf("%lf\n%lf\n",ex,s);
    }
    return 0;
}
