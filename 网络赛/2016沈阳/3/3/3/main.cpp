//
//  main.cpp
//  3
//
//  Created by wzcjj on 16/9/18.
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
#define maxn 1000005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

long long a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n=1000000,N,k;
    cin>>N;
    a[0]=1;
    for(i=1;i<=n;i++)a[i]=a[i-1]*i%P;
    while (N--) {
        scanf("%d%d%d",&n,&m,&k);
        if(m==1){
            printf("%d\n",n);
        }
        else {
            n-=m*k;
        }
    }
    return 0;
}
