//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/7/2.
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
#define maxn 105
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    int cnt=1;
    n=11;
    for(i=0;i<=n;i++){
        for(j=1;j<=i;j++){
            if(i&1)a[i][j]=cnt++;
            else a[j][i]=cnt++;
        }
        for(j=i-1;j>=1;j--){
            if(i&1)a[j][i]=cnt++;
            else a[i][j]=cnt++;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            b[i][j]=a[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            c[i][j]=b[i][j]+c[i-1][j]+c[i][j-1]-c[i-1][j-1];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    /*cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
    }*/
    return 0;
}
