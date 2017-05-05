//
//  main.cpp
//  exgcd
//
//  Created by wzcjj on 15/11/23.
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
#define maxn 10005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

int exgcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    if(a < b)return exgcd(b, a, y, x);
    else {
        int t = exgcd(b, a % b, y, x);
        y = y - a / b * x;
        return t;
    }
}
int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while(cin>>m>>n){
        int x,y;
        int t = exgcd(m, n, x, y);
        cout<<t<<' '<<x<<' '<<y<<endl;
    }
    return 0;
}
