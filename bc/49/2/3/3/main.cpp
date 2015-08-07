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
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 10005
#define P (1<<32)
#define INF 2100000000
using namespace std;

int gcd(int x,int y){
    if(x<y)swap(x,y);
    if(y==0)return x;
    else return gcd(y,x%y);
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}
int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k,l;
    for(n=1;n<=10;n++){
        unsigned ans=0;
        memset(a, 0, sizeof(a));
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                for(k=1;k<=n;k++)
                    for(l=1;l<=n;l++){
                        int t=lcm(gcd(i,j),gcd(k,l));
                        a[t]++;
                        ans+=t;
                    }
        for(i=1;i<=n*(n-1);i++)cout<<a[i]<<' ';
        cout<<endl;
        cout<<ans<<endl;
    }
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
    }
    return 0;
}
