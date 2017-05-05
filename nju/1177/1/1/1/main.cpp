//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/3/17.
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

struct node {
    double v;
    int i;
    friend bool operator<(node x,node y){
        return x.v<y.v;
    }
};
node a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    N=1;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%lf",&a[i].v);
            a[i].i=i;
        }
        sort(a+1,a+1+n);
        for(i=n;i>1;i--){
            printf("%d ",a[i].i);
        }
        printf("%d\n",a[1].i);
    }
    return 0;
}