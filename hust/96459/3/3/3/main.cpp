//
//  main.cpp
//  3
//
//  Created by wzcjj on 15/10/23.
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
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define read1(i) ((s1[i]-'0')*100+(s1[i+1]-'0')*10+(s1[i+2]-'0'))
using namespace std;

int dp[maxn][maxn];
char s1[maxn],s2[maxn];
bool flag[maxn*maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%s%s",s1,s2)!=EOF) {
        memset(dp,127,sizeof(dp));
        memset(flag,0,sizeof(flag));
        dp[0][read1(1)]=0;
        queue<int> q;
        while(!q.empty())q.pop();
        q.push(read1(1));
        flag[read1(1)]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            flag[x]=0;
            int y=x%1000;
            x=x/1000;
            if(dp[x*1000+y-100])
        }
    }
    return 0;
}
