//
//  main.cpp
//  1
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
#define maxn 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
int b[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        b[0]=0;
        for(i=1;i<=n;i++){
            b[i]=(b[i-1]+a[i])%m;
        }
        sort(b,b+1+n);
        int z=0;
        for(i=0;i<n;i++)if(b[i]==b[i+1]){
            z=1;
            break;
        }
        if(z)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
