//
//  main.cpp
//  2
//
//  Created by wzcjj on 15/8/8.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 70
#define P 1000000007
#define INF 2100000000
using namespace std;

long long a[maxn]={0,1,2,3,5,8,12,18,27,40,59,87,128,188,276,405,594,871,1277,1872,2744,4022,5895,8640,12663,18559,27200,39864,58424,85625,125490,183915,269541,395032,578948,848490,1243523,1822472,2670963,3914487,5736960,8407924,12322412,18059373,26467298,38789711,56849085,83316384,122106096,178955182,262271567,384377664,563332847,825604415,1209982080,1773314928,2598919344LL,3808901425LL,5582216354LL,8181135699LL,11990037125LL};
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d",&n)!=EOF) {
        printf("%I64d\n",a[n]);
    }
    return 0;
}
