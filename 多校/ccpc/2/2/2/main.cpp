//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/8/14.
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
#define maxn 305
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

long long a[maxn];
int b[maxn];
bool c[maxn][maxn];
bool flag[2005];
int dp[maxn][maxn][2];
int main(int argc, const char * argv[]) {
    int i,j,m=0,n=2000,N,I=0;
    memset(flag, 0, sizeof(flag));
    for(i=2;i<=n;i++)if(!flag[i]){
        for(j=2;i*j<=n;j++){
            flag[i*j]=true;
        }
    }
    for(i=2;i<=n;i++){
        if(!flag[i]){
            b[++m]=i;
        }
    }
    cin>>N;
    while (N--) {
        I++;
        printf("Case #%d:\n",I);
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        memset(c, 0, sizeof(c));
        memset(dp, 0, sizeof(dp));
        //memset(flag, 0, sizeof(flag));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                //if(a[i]==1)break;
                while(a[i]%b[j]==0){
                    c[i][j]=!c[i][j];
                    a[i]/=b[j];
                }
            }
        }
        int cnt=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(c[i][j]){
                    for(int k=i+1;k<=n;k++){
                        if(c[k][j]){
                            for(int l=j;l<=m;l++)c[k][l]^=c[i][l];
                        }
                    }
                    break;
                }
            }
            if(j==m+1)cnt++;
        }
        /*int cnt=n;
        for(i=1;i<=m;i++){
            bool z=0;
            for(j=1;j<=n;j++){
                if(c[j][i]){
                    z=1;
                    break;
                }
            }
            if(z)cnt--;
        }*/
        int ans=1;
        for(i=1;i<=cnt;i++){
            ans<<=1;
            if(ans>=P)ans-=P;
        }
        ans--;
        printf("%d\n",ans);
    }
    return 0;
}
