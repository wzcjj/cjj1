//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/3/11.
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
#define maxn 105
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

int a[maxn],b[maxn],dp[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    N=1;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)scanf("%d",&b[i]);
        int x;
        dp[0]=0;
        x=1;
        for(i=1;i<=n;i++){
            while(a[i]-a[x]>5)x++;
            dp[i]=max(dp[i-1],dp[x-1]+b[i]);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
