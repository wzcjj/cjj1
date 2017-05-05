//
//  main.cpp
//  3
//
//  Created by wzcjj on 16/10/6.
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
    int i,j,m,n,N,I=0;
    cin>>N;
    while (N--) {
        I++;
        long long x,y;
        scanf("%lld%lld",&x,&y);
        printf("Case #%d:\n",I);
        if(x==y){
            printf("1\n");
            printf("%lld %lld\n",x,y);
        }
        else {
            printf("2\n");
            printf("%lld %lld\n",x,y);
            printf("%lld %lld\n",y,x);
        }
    }
    return 0;
}
