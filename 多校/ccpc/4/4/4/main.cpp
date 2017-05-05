//
//  main.cpp
//  4
//
//  Created by wzcjj on 16/8/14.
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
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int ma=0,sum=0;
        for(i=1;i<=n;i++){
            if(a[i]>ma)ma=a[i];
            sum+=a[i];
        }
        if(sum>=(sum-ma)*4+2){
            printf("Case #%d: %d\n",I,(sum-ma)*2+1);
        }
        else {
            printf("Case #%d: %d\n",I,sum/2);
        }
    }
    return 0;
}
