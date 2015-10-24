//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/10/14.
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
#define maxn 10005
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn];
int b[maxn];
int gcd(int x,int y){
    if(y==0)return x;
    else return gcd(y,x%y);
}
long long sqrtt(long long x){
    unsigned long long l=0,r=(1LL<<32)-1;
    while(l<r-1){
        unsigned long long mid= (l+r)>>1;
        if(mid*mid<=x)l=mid;
        else r=mid;
    }
    return l;
}
long long f(long long x){
    long long t=(long long)(sqrtt(x));
    long long ans=x/2-1;
    if((t&1)==0)ans--;
    return ans;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    /*for(n=1;n<=5000;n++){
        for(i=1;i<=n;i++){
            if(n%i&&gcd(n,i)!=1)a[n]++;
        }
    }
    for(i=1;i<=5000;i++){
        b[i]=b[i-1]+(a[i]&1);
    }
    for(i=1;i<=5000;i++){
        if(b[i]!=f(i))cout<<i<<endl;
    }*/
    cin>>N;
    while (N--) {
        long long x,y;
        scanf("%lld%lld",&x,&y);
        if(x<6)x=6;
        if(y<5)y=5;
        long long ans = f(y)-f(x-1);
        printf("%lld\n",ans);
    }
    return 0;
}
