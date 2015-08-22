//
//  main.cpp
//  4
//
//  Created by wzcjj on 15/8/18.
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
#define maxn 105
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn][maxn];
int b[maxn];
long long c[maxn];
bool flag[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    c[0]=1;
    for(i=1;i<=100;i++)c[i]=c[i-1]*i%P;
    while (scanf("%d%d",&n,&m)!=EOF) {
        int sum=0;
        bool z=true;
        for(i=1;i<=m;i++){
            memset(flag,0,sizeof(flag));
            scanf("%d",&a[i][1]);
            flag[a[i][1]]=true;
            if(a[i][1]==-1){
                sum++;
            }
            else for(j=2;j<=n;j++){
                scanf("%d",&a[i][j]);
                if(flag[a[i][j]])z=false;
                flag[a[i][j]]=true;
            }
        }
        if(!z){
            puts("0");
            continue;
        }
        if(sum==0){
            for(i=1;i<=n;i++)b[i]=i;
            for(i=m;i>=1;i--)for(j=1;j<=n;j++)b[j]=a[i][b[j]];
            int flag=true;
            for(i=1;i<=n;i++)if(b[i]!=i){
                flag=false;
                break;
            }
            if(flag)puts("1");
            else puts("0");
        }
        else{
            long long ans=1;
            for(i=1;i<sum;i++)ans=ans*c[n]%P;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
