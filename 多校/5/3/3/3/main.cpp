//
//  main.cpp
//  3
//
//  Created by wzcjj on 16/8/2.
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

int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d",&n)!=EOF) {
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        long long sum=0,ans=0;
        for(i=n;i>=1;i--){
            if(sum+a[i]>=0){
                ans++;
                sum=0;
            }
            else {
                sum+=a[i];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
