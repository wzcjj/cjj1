//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/8/4.
//  Copyright (c) 2016年 wzcjj. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;
#define is(X)
typedef long long LL;
using namespace std;
#define mod 110119

LL n,M,r;

long long F[120005];
void init(long long p)
{
    F[0] = 1;
    for(LL i = 1;i <= p;i++)
        F[i] = F[i-1]*i % mod;
}
//a^b%mod 快速幂
long long Quk_Mul(long long a,long long b,long long m)
{
    //is(a);is(b);
    long long qsum=1;
    while(b)
    {
        if(b&1) qsum=(qsum*a)%m;
        b>>=1;
        a=(a*a)%m;
    }
    return qsum;
}
LL inv(LL A,LL m)
{
    return Quk_Mul(A, m-2, m);
}
long long Lucas(long long n,long long m,long long p)
{
    long long ans = 1;
    while(n&&m)
    {
        long long a = n%p;
        long long b = m%p;
        //is(a);is(b);
        if(a < b)return 0;
        //is(a);is(b);
        //is(F[a]);is(inv(F[b]*F[a-b]%p,p));
        ans = ans*F[a]%p*inv(F[b]*F[a-b]%p,p)%p;
        n /= p;
        m /= p;
    }
    //is(ans);
    return ans;
}
/*
 
 560000000000000000
 285000000000000000
 0
 */
struct A{
    LL x,y;
}ob[105];
int main()
{
    init(mod+5);
    int cc = 1;
    while(cin >> n >> M >> r) {
        if((n+M)%3 != 2) {
            for(int i = 0;i < r;i++) {
                scanf("%*lld%*lld");
            }
            printf("Case #%d: 0\n",cc++);
            continue;
        }
        LL dep = (n+M-2)/3;
        LL k = (n-M+dep)/2;
        //is(dep);is(k);
        if(k < 0 || k > dep) {
            for(int i = 0;i < r;i++) {
                scanf("%*lld%*lld");
            }
            printf("Case #%d: 0\n",cc++);
            continue;
        }
        //is(dep);is(k);
        LL ans = Lucas(dep,k,mod);
        //is(ans);
        for(int i = 0;i < r;i++) {
            LL x,y;scanf("%lld%lld",&x,&y);
            
            ob[i].x = x;ob[i].y = y;
            bool flag = false;
            for(int j = 0;j < i;j++) {
                if(x == ob[j].x && y == ob[j].y) {
                    flag = true;
                    break;
                }
            }
            
            if(flag) continue;
            if((x+y)%3 != 2) continue;
            dep = (x+y-2)/3;
            k = (x-y+dep)/2;
            if(k < 0 || k > dep) continue;
            LL tmp = Lucas(dep,k,mod);
            
            x = n-x+1;y = M-y+1;
            dep = (x+y-2)/3;
            k = (x-y+dep)/2;
            //is(dep);is(k);
            if(k < 0 || k > dep) continue;
            
            //is(Lucas(dep,k,mod));is(tmp);
            ans -= Lucas(dep,k,mod) * tmp % mod;
            ans = (ans + mod) % mod;
            
            for(int j=0;j<r;j++){
                for(int k=j+1;k<r;k++){
                    
                }
            }
        }
        if(n == 1 && M == 1) ans = 1;
        printf("Case #%d: ",cc++);
        cout << ans << endl;
    }
    return 0;
}