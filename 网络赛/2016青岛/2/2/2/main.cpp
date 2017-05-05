//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/9/17.
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
#define maxn 1000005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

double a[maxn];
char s[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n=1000000,N;
    a[0]=0;
    for(i=1;i<=n;i++){
        a[i]=a[i-1]+1.0/i/i;
    }
    while (scanf("%s",s)!=EOF) {
        if(strlen(s)>=7)m=n;
        else sscanf(s, "%d",&m);
        printf("%.5lf\n",a[m]);
    }
    return 0;
}
