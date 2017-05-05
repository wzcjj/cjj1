//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/11/21.
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
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

int a[maxn];
int dp[maxn][maxn][maxn];
int ans[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d%d",&n,&m)!=EOF) {
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=dp[0][0][1]=1;
        a[0]=-1;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                for(int k=0;k<i;k++)if(a[i]>a[k]){
                    for(int l=1;l<=max(dp[k][j-1][0],dp[i][j][0]);l++){
                        dp[i][j][l]+=dp[k][j-1][l];
                    }
                    for(int l=1;l<=max(dp[i][j][0],dp[k][j-1][0]);l++){
                        if(dp[i][j][l]>9){
                            dp[i][j][l+1]+=dp[i][j][l]/10;
                            dp[i][j][l]%=10;
                        }
                    }
                    dp[i][j][0]=max(dp[k][j-1][0],dp[i][j][0]);
                        while(dp[i][j][dp[i][j][0]+1]){
                            dp[i][j][0]++;
                        }
                }
            }
        }
        memset(ans,0,sizeof(ans));
        for(i=1;i<=n;i++){
            for(j=1;j<=max(dp[i][m][0],ans[0]);j++){
                ans[j]+=dp[i][m][j];
            }
            for(j=1;j<=max(ans[0],dp[i][m][0]);j++){
                if(ans[j]>9){
                    ans[j+1]+=ans[j]/10;
                    ans[j]%=10;
                }
            }
            ans[0]=max(ans[0],dp[i][m][0]);
            while(ans[ans[0]+1])ans[0]++;
        }
        if(ans[0]==0)printf("0");
        for(j=ans[0];j>=1;j--)printf("%d",ans[j]);
        printf("\n");
    }
    return 0;
}
