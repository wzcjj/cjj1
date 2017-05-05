//
//  main.cpp
//  4
//
//  Created by wzcjj on 16/7/30.
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
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn][maxn];
int pow(int x,int y){
    long long t=1,s=x;
    for(int i=0;(1<<i)<=y;i++){
        if((1<<i)&y){
            t=t*s%P;
        }
        s=s*s%P;
    }
    return t;
}
int main(int argc, const char * argv[]) {
    int i,j,m=60,n=60,N;
    for(j=1;j<=m;j++)a[1][j]=1;
    for(i=2;i<=n;i++){
        for(j=1;j<=m;j++){
            if(i<j)a[i][j]=pow(2,i*(i-1)/2);
            
        }
    }
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
    }
    return 0;
}
