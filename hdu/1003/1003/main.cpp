//
//  main.cpp
//  1003
//
//  Created by wzcjj on 16/9/1.
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
        int maxx=-INF,maxl,maxr;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]>maxx&&a[i]<0){
                maxx=a[i];
                maxl=maxr=i;
            }
        }
        int l=0,sum=0;
        for(i=1;i<=n;i++){
            sum+=a[i];
            if(sum>maxx){
                maxx=sum;
                maxl=l+1;
                maxr=i;
            }
            if(sum<0){
                l=i;
                sum=0;
            }
        }
        printf("Case %d:\n",I);
        printf("%d %d %d\n",maxx,maxl,maxr);
        if(N)printf("\n");
    }
    return 0;
}
