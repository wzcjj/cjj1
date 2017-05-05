//
//  main.cpp
//  5
//
//  Created by wzcjj on 16/10/6.
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
#define maxn 35
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I=0;
    cin>>N;
    while (N--) {
        I++;
        scanf("%d%d",&m,&n);
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        bool flag=0;
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                if(a[i][j]==a[i][j+1]||a[i][j]==a[i+1][j]){
                    flag=true;
                }
            }
        }
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(a[1][i]==a[1][j]||a[m][i]==a[m][j])flag=true;
            }
        }
        for(i=1;i<=m;i++){
            for(j=i+1;j<=m;j++){
                if(a[i][1]==a[j][1]||a[i][n]==a[j][n])flag=true;
            }
        }
        if(flag){
            printf("Case #%d: Yes\n",I);
        }
        else {
            printf("Case #%d: No\n",I);
        }
    }
    return 0;
}
