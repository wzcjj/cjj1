//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/10/2.
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

int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    int x0,x1,x2,y0,y1,y2,z0,z1,z2;
    scanf("%d%d%d%d%d%d%d%d%d",&x0,&y0,&z0,&x1,&y1,&z1,&x2,&y2,&z2);
    long long ans=0;
    if(x0<x1)ans+=(x1-x0)*(x1-x0);
    if(x0>x2)ans+=(x2-x0)*(x2-x0);
    if(y0<y1)ans+=(y1-y0)*(y1-y0);
    if(y0>y2)ans+=(y2-y0)*(y2-y0);
    if(z0<z1)ans+=(z1-z0)*(z1-z0);
    if(z0>z2)ans+=(z2-z0)*(z2-z0);
    printf("%lld\n",ans);
    return 0;
}
