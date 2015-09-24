//
//  main.cpp
//  4
//
//  Created by wzcjj on 15/9/12.
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
#define maxn 405
#define P 1000000007
#define INF 2100000000
using namespace std;

struct node{
    long long l,v;
};
int l[maxn],r[maxn];
long long dp[maxn][55][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
        for(i=1;i<=n;i++){
            for(j=0;j<=m;j++){
                for(k=1;k<=i-1;k++){
                    dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][k]+(r[i]-l[i]+2)*(r[i]-l[i]+1)/2);
                    if(m-j>=l[i]-r[i-1]-1){
                        dp[i][j+l[i]-r[i-1]-1][k+1]=max(dp[i][j+l[i]-r[i-1]-1][k+1],dp[i-1][j][k]+(r[i]-r[i-1])*(2*(r[i-1]-l[i-k]+1)+1+r[i]-r[i-1])/2);
                    }
                }
            }
        }
        long long ans=0;
        for(j=0;j<=m;j++)for(k=1;k<=n;k++)if(dp[n][j][k]>ans)ans=dp[n][j][k];
        cout<<ans<<endl;
    }
    return 0;
}
