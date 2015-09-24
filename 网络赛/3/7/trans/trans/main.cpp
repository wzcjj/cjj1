//
//  main.cpp
//  trans
//
//  Created by wzcjj on 15/9/20.
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
#define maxn 8
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    freopen("fw.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (scanf("%d",&n)!=EOF) {
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        scanf("%d",&m);
        printf("ans[%d][%d][%d][%d][%d][%d][%d][%d]=%d;\n",n,a[1],a[2],a[3],a[4],a[5],a[6],a[7],m);
    }
    return 0;
}
