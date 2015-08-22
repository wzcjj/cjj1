//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/8/13.
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
#define maxn 1000005
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn],f[maxn],s[maxn];
long long gcd(int x,int y){
    if(x<y)swap(x,y);
    if(y==0)return x;
    return gcd(y,x%y);
}
long long lcm(int x,int y){
    long long ans=x;
    ans*=y;
    ans/=gcd(x,y);
    return ans;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    memset(f,0,sizeof(f));
    memset(s,0,sizeof(s));
    for(n=1;n<=20;n++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(gcd(i,j)+lcm(i,j)>=n)f[n]++;
            }
        }
    }
    for(i=1;i<n;i++){
        s[i]=s[i-1]+f[i];
    }
    for(i=2;i<n;i++)cout<<f[i]-f[i-1]<<endl;
    cout<<endl;
    for(i=1;i<n;i++)cout<<f[i]<<endl;
    cout<<endl;
    for(i=1;i<n;i++)cout<<s[i]<<endl;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
    }
    return 0;
}
