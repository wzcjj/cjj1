//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/8/15.
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
#define P 3221225473LL
#define INF 2100000000
using namespace std;

#define BUFSIZE 20000000
char buf[BUFSIZE], *pt = buf;
#define scan(t) do { \
t = 0; \
while (!((*pt) >= '0' && (*pt) <= '9')) pt ++; \
while (((*pt) >= '0' && (*pt) <= '9')) t = t * 10 + (*(pt ++)) - '0'; \
} while (0)
unsigned long long a[maxn];
bool fl[maxn];
unsigned long long niyuan(unsigned long long n,unsigned long long a){
    if(a==1)return 1;
    unsigned long long b1=0,b2=1,b3,q,r1,r2,r3;
    r1=n;
    r2=a;
    q=r1/r2;
    r3=r1%r2;
    b3=b1-q*b2;
    while(r3>1){
        r1=r2;
        r2=r3;
        b1=b2;
        b2=b3;
        q=r1/r2;
        r3=r1%r2;
        b3=b1-q*b2;
    }
    return (b3+n)%n;
}

unsigned long long gcd(unsigned long long x,unsigned long long y){
    if(x<y)swap(x,y);
    if(y==0)return x;
    return gcd(y,x%y);
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&j);
            a[j]=i;
        }
        memset(fl,0,sizeof(fl));
        unsigned long long ans=1,gc=-1;
        for(i=1;i<=n;i++){
            if(!fl[i]){
                unsigned long long t=1;
                for(j=a[i];j!=i;j=a[j]){
                    t++;
                    fl[j]=true;
                }
                if(gc==-1)gc=t;
                else gc=gcd(gc,t);
                ans=ans*t%P;
                if(i>1)ans=ans*niyuan(P,gc)%P;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
