//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/11/17.
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
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;

char a[maxn];
int dp[maxn][maxn];
void pr(int x,int y){
    if(x>y)return;
    if(x==y){
        if(a[x]=='('||a[x]==')')printf("()");
        else printf("[]");
        return;
    }
    if(dp[x][y]==dp[x+1][y-1]&&((a[x]=='('&&a[y]==')')||(a[x]=='['&&a[y]==']'))){
        printf("%c",a[x]);
        pr(x+1,y-1);
        printf("%c",a[y]);
        return;
    }
    for(int i=x;i<y;i++)if(dp[x][y]==dp[x][i]+dp[i+1][y]){
        pr(x,i);
        pr(i+1,y);
        return;
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k;
    scanf("%s",a);
    n = strlen(a);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)dp[i][j]=INF;
        dp[i][i-1]=0;
        dp[i][i]=1;
    }
    for(i=2;i<=n;i++){
        for(j=0;j<n-i+1;j++){
            for(k=j;k<=j+i-1;k++){
                dp[j][j+i-1]=min(dp[j][j+i-1], dp[j][k]+dp[k+1][j+i-1]);
            }
            if((a[j]=='('&&a[j+i-1]==')')||(a[j]=='['&&a[j+i-1]==']'))dp[j][j+i-1]=min(dp[j][j+i-1], dp[j+1][j+i-2]);
        }
    }
    pr(0,n-1);
    printf("\n");
    return 0;
}
