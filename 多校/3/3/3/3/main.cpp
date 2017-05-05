//
//  main.cpp
//  3
//
//  Created by wzcjj on 16/7/26.
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
#define maxn 1005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[5][maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n=1000,N,o;
    memset(a,0,sizeof(a));
    a[1][1][1]=0;
    for(i=2;i<=n;i++){
        a[1][1][i]=a[1][i][1]=!(i&1);
    }
    for(i=2;i<=n;i++){
        for(j=2;j<=n;j++){
            a[1][i][j]=!(a[1][i-1][j]&&a[1][i-1][j-1]&&a[1][i][j-1]);
        }
    }
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            a[2][i][j]=!(i==j);
        }
    }
    
    a[3][1][1]=0;
    for(i=2;i<=n;i++){
        a[3][1][i]=a[3][i][1]=-1;
        a[3][2][i]=a[3][i][2]=-1;
    }
    a[3][2][3]=a[3][3][2]=1;
    for(i=3;i<=n;i++){
        for(j=3;j<=n;j++){
            if(a[3][i-2][j-1]==1&&a[3][i-1][j-2]==1)a[3][i][j]=0;
            else if(a[3][i-2][j-1]==0||a[3][i-1][j-2]==0)a[3][i][j]=1;
            else a[3][i][j]=-1;
        }
    }
    
    a[4][1][1]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(!a[4][i][j]){
                for(int k=1;k<=n-max(i,j);k++)a[4][i+k][j+k]=1;
                for(int k=1;k<=n-i;k++)a[4][i+k][j]=1;
                for(int k=1;k<=n-j;k++)a[4][i][j+k]=1;
            }
        }
    }
    cin>>N;
    while (N--) {
        scanf("%d%d%d",&o,&n,&m);
        if(a[o][n][m]==1)printf("B\n");
        else if(a[o][n][m]==0)printf("G\n");
        else printf("D\n");
    }
    return 0;
}
