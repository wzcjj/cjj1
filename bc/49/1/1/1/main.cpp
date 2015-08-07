//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/7/30.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
//#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 1000005
#define P 1000000007
#define INF 2100000000
using namespace std;

int b[maxn],a[30];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        memset(b,-1,sizeof(b));
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int ans=n+1;
        b[m]=0;
        for(i=n;i>=1;i--){
            for(j=1;j<=1000000;j++)if(b[j]>=0){
                int t=j%a[i];
                if(b[t]==-1||b[t]>b[j]+1)b[t]=b[j]+1;
            }
        }
        printf("%d\n",b[0]);
    }
    return 0;
}
