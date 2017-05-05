//
//  main.cpp
//  7
//
//  Created by wzcjj on 16/9/18.
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
#define maxn 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

long long dp[20][2][2];
long long calc(long long x){
    long long t=1,n;
    for(n=0;n<18;n++){
        t*=10;
        if(t>x)break;
    }
    if(!n){
        return x/2+1;
    }
    t=1;
    for(int i=1;i<=n;i++)t*=10;
    long long ans=0;
    long long s=x/t;
    ans+=calc(t-1);
    ans+=(s)/2*(dp[n][1][1]);
    ans+=(s-1)/2*(dp[n][1][0]+dp[n][0][0]);
    long long s1=x%t*10/t;
    if(s&1){
        ans+=s1/2*(dp[n-1][0][1]+dp[n-1][1][0]);
        if(s1&1){
            ans+=calc(x%(t/10));
        }
    }
    else {
        ans+=s1/2*(dp[n-1][0][1]+dp[n-1][1][0]);
        ans+=s1/2*dp[n-1][1][1];
        if(s1&1){
            if(n>1){
                long long s2=x%(t/10)*10/t;
                ans+=s2/2*(dp[n-2][0][1]+dp[n-2][1][1]);
                if(s2&1){
                    ans+=calc(x%(t/100));
                }
            }
        }
        else {
            ans+=calc(x%(t/10));
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n=18,N,k,I=0;
    memset(dp, 0, sizeof(dp));
    //dp[0][0][1]=
    dp[0][1][0]=1;
    for(i=1;i<=n;i++){
        dp[i][0][0]=dp[i-1][0][1]*5;
        dp[i][0][1]=dp[i-1][0][0]*5+dp[i-1][1][0]*5;
        dp[i][1][0]=dp[i-1][1][1]*5;
        dp[i][1][1]=dp[i-1][1][0]*5+dp[i-1][0][1]*5;
    }
    cin>>N;
    while (N--) {
        I++;
        long long l,r;
        scanf("%lld%lld",&l,&r);
        printf("Case #%d: %lld\n",I,calc(r)-calc(l-1));
    }
    return 0;
}
