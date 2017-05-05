//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/8/6.
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

int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        long long sum=0;
        for(i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            sum+=x;
        }
        for(i=1;i<=m;i++){
            long long x;
            scanf("%lld",&x);
            if(x>sum)printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}
