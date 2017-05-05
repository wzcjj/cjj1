//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/4/1.
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
#define maxn 5005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

int a[maxn];
int dp[maxn],dp1[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    N=1;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        a[0]=a[n+1]=-1;
        memset(dp,0,sizeof(dp));
        memset(dp1,0,sizeof(dp1));
        for(i=1;i<=n;i++){
            for(j=0;j<i;j++){
                if(a[i]>a[j]&&dp[i]<dp[j]+1)dp[i]=dp[j]+1;
            }
        }
        for(i=n;i>=1;i--){
            for(j=n+1;j>i;j--){
                if(a[i]>a[j]&&dp1[i]<dp1[j]+1)dp1[i]=dp1[j]+1;
            }
        }
        int ans=0;
        for(i=1;i<=n;i++){
            if(dp[i]>ans)ans=dp[i];
        }
        printf("%d ",ans);
        ans=0;
        for(i=1;i<=n;i++){
            if(ans<dp[i]+dp1[i]-1)ans=dp[i]+dp1[i]-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
