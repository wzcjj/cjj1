//
//  main.cpp
//  3
//
//  Created by wzcjj on 15/8/29.
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
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn],b[maxn];
int de[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d",&n)!=EOF) {
        de[1]=1;
        memset(a, 0, sizeof(a));
        a[1]=1;
        for(i=2;i<=n;i++){
            scanf("%d",&j);
            de[i]=de[j]+1;
            a[de[i]]++;
        }
        b[0]=0;
        double ans=0;
        for(i=1;i<=n&&b[i-1]<n;i++)b[i]=b[i-1]+a[i];
        for(i--;i>1;i--){
            
        }
    }
    return 0;
}
