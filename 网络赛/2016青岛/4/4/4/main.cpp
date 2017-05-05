//
//  main.cpp
//  4
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
    long long l,r;
    while (scanf("%lld%lld",&l,&r)!=EOF) {
        if(r<=1){
            printf("0\n");
        }
        else if(r<=2){
            printf("1\n");
        }
        else if(l==0){
            printf("%lld\n",(r+1)/2);
        }
        else {
            if(r-l<=3)printf("2\n");
            else printf("%lld\n",(r-l)/2+1);
        }
    }
    return 0;
}
