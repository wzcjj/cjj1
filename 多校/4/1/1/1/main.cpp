//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/7/28.
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

int a[maxn];
int flag[maxn];
int nex[maxn];
int l1,l2;
char W[maxn],T[maxn];
long long dp[maxn];
void getNext(){
    nex[0]=-1;
    int j=-1;
    for(int i=1;i<l2;i++){
        while(j>-1&&W[j+1]!=W[i])j=nex[j];
        if(W[j+1]==W[i])j++;
        nex[i]=j;
    }
}
int KMP(){
    int i,j=-1;
    for(i=0;i<l1;i++){
        while(j>-1&&W[j+1]!=T[i])j=nex[j];
        if(W[j+1]==T[i])j++;
        if(j==l2-1){
            flag[i-j]=1;
            //return i-j;
            //ans++;
            j=nex[j];
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I=0;
    cin>>N;
    while (N--) {
        I++;
        memset(flag,0,sizeof(flag));
        memset(nex,0,sizeof(nex));
        memset(dp,0,sizeof(dp));
        scanf("%s%s",T,W);
        l1=strlen(T);
        l2=strlen(W);
        getNext();
        KMP();
        for(i=l1-l2+1;i<=l1;i++)dp[i]=1;
        for(i=l1-l2;i>=0;i--){
            dp[i]=(dp[i+1]+dp[i+l2]*(flag[i]))%P;
        }
        printf("Case #%d: %lld\n",I,dp[0]);
    }
    return 0;
}
