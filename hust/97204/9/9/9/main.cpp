//
//  main.cpp
//  9
//
//  Created by wzcjj on 15/10/28.
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
#define maxn 10005
#define P 1000000007
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;

int dp[205][100][2][5][5][5];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k,l,p,q;
    cin>>N;
    int I=0;
    while (N--) {
        I++;
        scanf("%d%d",&n,&m);
        m/=3;
        memset(dp,0,sizeof(dp));
        dp[1][0][0][0][0][0]=1;
        for(i=1;i<=n;i++){
            for(j=0;j<=m;j++){
                for(k=0;k<=1;k++){
                    for(l=0;l<=4;l++){
                        for(p=0;p<=4;p++){
                            for(q=0;q<=4;q++){
                                if(k==0&&l<=2){
                                    dp[i][j][k+1][l+2][p][q]=(dp[i][j][k][l][p][q]+dp[i][j][k+1][l+2][p][q])%P;
                                }
                                if(l<2){
                                    dp[i][j+1][k][l+3][p][q]=(dp[i][j][k][l][p][q]+dp[i][j+1][k][l+3][p][q])%P;
                                }
                                if(l<4&&p<4&&q<4&&i+2<=n){
                                    dp[i][j+1][k][l+1][p+1][q+1]=(dp[i][j+1][k][l+1][p+1][q+1]+dp[i][j][k][l][p][q])%P;
                                }
                                if(k==0&&l<2&&p<4&&q<4&&i+2<=n)dp[i][j+1][k+1][l+3][p+1][q+1]=(dp[i][j+1][k+1][l+3][p+1][q+1]-dp[i][j][k][l][p][q]+P)%P;
                                if(k==0&&l<4&&p<2&&q<4&&i+2<=n)dp[i][j+1][k+1][l+1][p+3][q+1]=(dp[i][j+1][k+1][l+1][p+3][q+1]-dp[i][j][k][l][p][q]+P)%P;
                                if(k==0&&l<4&&p<4&&q<2&&i+2<=n)dp[i][j+1][k+1][l+1][p+1][q+3]=(dp[i][j+1][k+1][l+1][p+1][q+3]-dp[i][j][k][l][p][q]+P)%P;
                                if(l==0&&p<4&&q<4&&i+2<=n)dp[i][j+2][k][l+4][p+1][q+1]=(dp[i][j+2][k][l+4][p+1][q+1]-dp[i][j][k][l][p][q]+P)%P;
                                if(l<=1&&p<=1&&q<=1&&i+2<=n)dp[i][j+3][k][l+3][p+3][q+3]=(dp[i][j+3][k][l+3][p+3][q+3]-dp[i][j][k][l][p][q]+P)%P;
                                dp[i+1][j][k][p][q][0]=(dp[i][j][k][l][p][q]+dp[i+1][j][k][p][q][0])%P;
                            }
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n",I,dp[n+1][m][1][0][0][0]);
    }
    return 0;
}
