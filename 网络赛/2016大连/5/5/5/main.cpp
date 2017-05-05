//
//  main.cpp
//  5
//
//  Created by wzcjj on 16/9/10.
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

int main(int argc, const char * argv[]) {
    long long h,l,k;
    while (scanf("%lld%lld%lld",&h,&l,&k)!=EOF) {
        long long ans=0;
        while(h){
            long long now=l/(k/h*h);
            if(l%(k/h*h)>k%h)now++;
            if(ans<now)ans=now;
            h--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
