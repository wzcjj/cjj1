//
//  main.cpp
//  5696
//
//  Created by wzcjj on 16/4/23.
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
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d %d\n%d %d\n",c,b+d,a,b+d);
    }
    return 0;
}