//
//  main.cpp
//  6
//
//  Created by wzcjj on 15/12/26.
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

char a[maxn][maxn];
int b[maxn][maxn];
int ans[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k;
    cin>>N;
    memset(b,0,sizeof(b));
    while (N--) {
        scanf("%d%d",&n,&m);
        memset(ans,0,sizeof(ans));
        for(i=1;i<=n;i++)scanf("%s",a[i]);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j-1]-'0';
                int l=0,r=min(i,j)+1;
                while(l<r-1){
                    int k=(l+r)>>1;
                    if(b[i][j]-b[i-k][j]-b[i][j-k]+b[i-k][j-k]==k*k)l=k;
                    else r=k;
                }
                ans[l]++;
            }
        }
        for(i=n-1;i>=1;i--){
            ans[i]+=ans[i+1];
        }
        for(int l=1;l<=m;l++){
            scanf("%d",&k);
            printf("%d\n",ans[k]);
        }
    }
    return 0;
}
