//
//  main.cpp
//  10
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
#define maxn 50005
#define P 1000000007
#define INF 2100000000
using namespace std;

struct node{
    int a[6];
};
node a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,ans;
    cin>>N;
    while (N--) {
        ans=0;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)for(j=1;j<=5;j++)scanf("%d",&a[i].a[j]);
    }
    return 0;
}
