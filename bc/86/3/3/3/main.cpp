//
//  main.cpp
//  3
//
//  Created by wzcjj on 16/8/6.
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
#define maxn 200005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k;
    cin>>N;
    while (N--) {
        scanf("%d%d%d",&n,&m,&k);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int cnt=0;
        i=1;
        j=0;
        long long ans=0;
        while(j<=n){
            while(j<=n&&cnt<k){
                j++;
                if(a[j]>=m)cnt++;
            }
            ans+=n-j+1;
            if(a[i]>=m)cnt--;
            i++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
