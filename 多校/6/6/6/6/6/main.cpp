//
//  main.cpp
//  6
//
//  Created by wzcjj on 16/8/4.
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

long long a[20][20];
int b[maxn];
long long ans2;
int hi,ans;
void dfs(int i,int x,long long sum){
    if(i==hi){
        if(ans2>sum||(ans2==sum&&ans>x)){
            ans2=sum;
            ans=x;
        }
    }
    else {
        for(b[i]=0;b[i]<2;b[i]++){
            long long su=sum+a[i][i];
            for(int j=0;j<i;j++){
                if(b[i]^b[j])su-=a[i][j];
                else su+=a[i][j];
            }
            dfs(i+1,x|(b[i]<<i),su);
        }
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m=20,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        memset(a, 0, sizeof(a));
        int x,y;
        scanf("%d",&x);
        for(i=1;i<n;i++){
            scanf("%d",&y);
            hi=m-1;
            while(hi>=0&&(((~(x^y))>>hi)&1))hi--;
            int ma=max(x,y);
            int mi=min(x,y);
            for(j=hi;j>=0;j--){
                a[hi][j]+=((ma>>j)&1)-((mi>>j)&1);
            }
            x=y;
        }
        hi=m;
        while(hi&&!a[hi-1][hi-1])hi--;
        for(i=0;i<m;i++){
            for(j=0;j<=i;j++){
                a[i][j]<<=j;
            }
        }
        ans2=1e18;
        dfs(0,0,0);
        printf("%d %lld\n",ans,ans2);
    }
    return 0;
}
