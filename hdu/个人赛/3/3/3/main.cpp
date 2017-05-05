//
//  main.cpp
//  3
//
//  Created by wzcjj on 15/12/26.
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
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) (((x) >= 0) ? (x) : (-(x)))
using namespace std;

int a[maxn],b[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    
    while (scanf("%d%d",&n,&m)!=EOF) {
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=m;i++)scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        long long ans=0;
        for(i=1;i<=n;i++){
            int l=1,r=m;
            while(l<r-1){
                if(b[(l+r)>>1]>a[i])r=(l+r)>>1;
                else l=(l+r)>>1;
            }
            ans+=min(abs(a[i]-b[l]),abs(a[i]-b[r]));
            //printf("%lld\n",ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
