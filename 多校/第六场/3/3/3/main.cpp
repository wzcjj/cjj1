//
//  main.cpp
//  3
//
//  Created by wzcjj on 15/8/6.
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
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;

vector<int> a[15];
bool b[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        long long t=n;
        t=n*(n+1)/2;
        if(t%m!=0){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(i=1;i<=m;i++)a[i].clear();
        memset(b,0,sizeof(b));
        t/=m;
        for(i=1;i<=m;i++){
            long long sum=0;
            for(j=n;j>=1;j--){
                if(t-sum==0)break;
                if(j>t-sum)j=t-sum;
                if(!b[j]){
                    a[i].push_back(j);
                    sum+=j;
                    b[j]=true;
                }
            }
        }
        for(i=1;i<=m;i++){
            printf("%d",a[i].size());
            for(j=0;j<a[i].size();j++)printf(" %d",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
