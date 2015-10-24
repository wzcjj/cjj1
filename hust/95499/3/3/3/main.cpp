//
//  main.cpp
//  3
//
//  Created by wzcjj on 15/10/16.
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
#define maxn 40
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d",&n)) {
        if(n==0)break;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)scanf("%d",&b[i][j]);
        }
        int ans,maxx=0;
        ans=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                c[i][j]=b[i][j];
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(c[i][j]==a[i][j])ans++;
            }
        }
        if(ans>maxx)maxx=ans;
        
        ans=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                c[i][j]=b[j][n-i+1];
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(c[i][j]==a[i][j])ans++;
            }
        }
        if(ans>maxx)maxx=ans;
        
        ans=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                c[i][j]=b[n-i+1][n-j+1];
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(c[i][j]==a[i][j])ans++;
            }
        }
        if(ans>maxx)maxx=ans;
        
        ans=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                c[i][j]=b[n-j+1][i];
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(c[i][j]==a[i][j])ans++;
            }
        }
        if(ans>maxx)maxx=ans;
        printf("%d\n",maxx);
    }
    return 0;
}
