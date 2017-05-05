//
//  main.cpp
//  1
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
#define maxn 2005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

double a[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m=16,n=2000,N;
    for(i=1;i<=n;i++)a[i][0]=INF;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            a[i][j]=INF;
            for(int k=1;k<=i;k++){
                if(a[i][j]>((a[i-k][j])*(i-k+1)+a[k-1][j-1]*(k))/(i+1)+1){
                    a[i][j]=((a[i-k][j])*(i-k+1)+a[k-1][j-1]*(k))/(i+1)+1;
                }
            }
        }
    }
    while (scanf("%d%d",&n,&m)!=EOF) {
        printf("%.6lf\n",a[n][min(m,16)]);
    }
    return 0;
}
