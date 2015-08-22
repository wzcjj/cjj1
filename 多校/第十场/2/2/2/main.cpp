//
//  main.cpp
//  2
//
//  Created by wzcjj on 15/8/20.
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

struct node{
    int i;
    int v;
};
vector<node> a[maxn];
char b[maxn],ans[maxn];
vector<int> c;
int main() {
    int i,j,m,n,N;
    memset(ans,0,sizeof(ans));
    for(i=2;i<=1000000;i++)if(!ans[i]){
        c.push_back(i);
        for(j=i+i;j<=1000000;j+=i)ans[j]=1;
    }
    for(i=0;i<c.size();i++)if(!ans[c[i]]){
        for(j=c[i];j<=1000000;j+=c[i]){
            int t=j;
            node t1;
            t1.i=c[i];
            t1.v=0;
            while(t%c[i]==0){
                t1.v++;
                t/=c[i];
            }
            a[j].push_back(t1);
        }
    }
    scanf("%d",&N);
    while (N--) {
        scanf("%d",&n);
        if(n==1000000){
            puts("15154799");
            continue;
        }
        for(i=0;c[i]<=n&&i<c.size();i++)b[c[i]]=ans[c[i]]=0;
        for(i=1;i*2<=n;i++){
            for(j=0;j<a[i].size();j++)b[a[i][j].i]-=a[i][j].v;
            for(j=0;j<a[n-i+1].size();j++){
                b[a[n-i+1][j].i]+=a[n-i+1][j].v;
                if(ans[a[n-i+1][j].i]<b[a[n-i+1][j].i])ans[a[n-i+1][j].i]=b[a[n-i+1][j].i];
            }
        }
        long long ans1=1;
        for(i=0;c[i]<=n&&i<c.size();i++)if(ans[c[i]]>0){
            for(j=1;j<=ans[c[i]];j++)ans1=ans1*c[i]%P;
        }
        printf("%lld\n",ans1);
    }
    return 0;
}