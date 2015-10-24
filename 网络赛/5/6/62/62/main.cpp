//
//  main.cpp
//  62
//
//  Created by wzcjj on 15/9/27.
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
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn];
struct node{
    int v,i;
    friend bool operator<(node x,node y){
        return x.v<y.v;
    }
};
node dp[maxn][2];
node find(int len,int y,int z){
    int l=0,r=len+1;
    while(l<r-1){
        int mid=(l+r)>>1;
        if(dp[mid][z].v<a[mid]&&dp[mid][z].i<=y)l=mid;
        else r=mid;
    }
    return dp[l][z];
}
node max(node x,node y){
    return x<y?x:y;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,len;
    cin>>N;
    int I=0;
    while (N--) {
        I++;
        len=0;
        memset(dp, 0, sizeof(dp));
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++){
            dp[i][0]=max(dp[i-1][0],find(len,i-1,0));
            dp[i][1]=max(max(dp[i-1][1],find(len,i-1,1)),find(len,i-1-m,0));
        }
    }
    return 0;
}
