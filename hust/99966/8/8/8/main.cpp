//
//  main.cpp
//  8
//
//  Created by wzcjj on 15/11/18.
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
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

int a[maxn];
int b[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d",&n)!=EOF) {
        long long ans = n;
        ans*=n+1;
        printf("%lld\n",ans);
        m=n;
        i=0;
        while((1<<i)-1<m)i++;
        i--;
        while(m>0){
            for(j=(1<<i);j<=m;j++){
                b[j]=(1<<(i+1))-j-1;
                b[(1<<(i+1))-j-1]=j;
            }
            m=(1<<(i+1))-m-2;
            while(i>=0&&(1<<i)-1>=m)i--;
        }
        if(m==0)b[0]=0;
        for(i=0;i<=n;i++){
            scanf("%d",&a[i]);
            printf("%d",b[a[i]]);
            if(i!=n)printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
