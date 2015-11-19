//
//  main.cpp
//  4
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
#define maxn 1005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

string s1,s2;
int dp[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (cin>>s1>>s2) {
        m=s1.length();
        n=s2.length();
        memset(dp,0,sizeof(dp));
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                if(s1[i-1]==s2[j-1])dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
