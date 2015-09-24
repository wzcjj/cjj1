//
//  main.cpp
//  2
//
//  Created by wzcjj on 15/8/26.
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

int a[maxn];
long long b[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    b[0]=0;
    for(i=1;i<=n;i++)b[i]=b[i-1]+a[i];
    j=1;
    for(i=1;i<=n;i++){
        while(j<n&&(((j-i)&1)==0||b[(i+j)>>1]-b[i-1]<=m))j++;
        if(b[(i+j)>>1]-b[i-1]>m)j--;
        while(j>=i&&(((j-i)&1)==0||(b[j]-b[(i+j)>>1]>m)))j--;
        printf("%d\n",j-i+1);
    }
    return 0;
}
