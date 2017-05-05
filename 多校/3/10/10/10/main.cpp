//
//  main.cpp
//  10
//
//  Created by wzcjj on 16/7/26.
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

int main(int argc, const char * argv[]) {
    int i,j,m,n,N,a,b,c;
    while (scanf("%d%d%d",&a,&b,&c)!=EOF) {
        if(a==0)printf("0\n");
        else if(b<=c)printf("Infinity\n");
        else printf("%.6lf\n",1.0*a/(b*b-c*c)*b);
    }
    return 0;
}
