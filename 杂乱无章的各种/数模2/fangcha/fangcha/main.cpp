//
//  main.cpp
//  fangcha
//
//  Created by wzcjj on 15/9/13.
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
#define maxn 105
#define P 1000000007
#define INF 2100000000
using namespace std;

long long a[maxn][maxn],b[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    char c[10];
    freopen("a.txt","r",stdin);
    for(i=0;i<100;i++){
        for(j=0;j<100;j++)scanf("%lld",&a[i][j]);
        scanf("%s",c);
    }
    fclose(stdin);
    freopen("b.txt","r",stdin);
    for(i=0;i<100;i++){
        for(j=0;j<100;j++)scanf("%lld",&b[i][j]);
        scanf("%s",c);
    }
    double ans=0;
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            ans+=(a[i][j]-b[i][j]*2)*(a[i][j]-b[i][j]*2);
        }
    }
    ans=ans/10000;
    freopen("c.txt","w",stdout);
    //for(i=0;i<100;i++)for(j=0;j<100;j++)printf("%lld %lld\n",a[i][j],b[i][j]);
    cout<<ans<<endl;
    return 0;
}
