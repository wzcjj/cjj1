//
//  main.cpp
//  6
//
//  Created by wzcjj on 16/9/24.
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
#define maxn 240005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;
typedef complex<double> E;
long long a[maxn],b[maxn];
const long double PI = 3.14159265358979323846264338327950288419716939937510;

E c[maxn],d[maxn],e[maxn],f[maxn],l[maxn],r[maxn];

void fft(E *x,int n,int type = 1)
{
    if(n==1)return;
    for(int i=0;i<n;i+=2)
        l[i>>1]=x[i],r[i>>1]=x[i+1];
    fft(l,n>>1,type);fft(r,n>>1,type);
    E wn(cos(2*PI/n),sin(type*2*PI/n)),w(1,0),t;
    for(int i=0;i<n>>1;i++,w*=wn)
        t=w*r[i],x[i]=l[i]+t,x[i+(n>>1)]=l[i]-t;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        long long sum=0;
        int len=1;
        while(len<n*2)len<<=1;
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            sum+=a[i]*a[i];
        }
        for(i=1;i<=n;i++){
            scanf("%lld",&b[i]);
            sum+=b[i]*b[i];
        }
        for(i=0;i<n;i++){
            c[i]=E(a[i+1],0);
            d[i]=E(b[n-i],0);
        }
        for(i=n;i<len;i++){
            c[i]=d[i]=E(0,0);
        }
        fft(c, len);
        fft(d, len);
        for(i=0;i<len;i++)e[i]=c[i]*d[i];
        fft(e,len,-1);
        for(i=0;i<n;i++){
            c[i]=E(a[n-i],0);
            d[i]=E(b[i+1],0);
        }
        for(i=n;i<len;i++){
            c[i]=d[i]=E(0,0);
        }
        fft(c, len);
        fft(d, len);
        for(i=0;i<len;i++)f[i]=c[i]*d[i];
        fft(f,len,-1);
        long long maxx=0;
        for(i=1;i<=n;i++){
            maxx+=a[i]*b[i];
        }
        for(i=1;i<n;i++){
            if(maxx*0.999999<(long long)(e[i-1].real()+0.5)+(long long)(f[(n-i)-1].real()+0.5)){
                long long summm=0;
                for(j=1;j<=n;j++){
                    summm+=a[j]*b[(j+n-i-1)%n+1];
                }
                if(maxx<summm)maxx=summm;
            }
        }
        printf("%lld\n",sum-2*maxx);
    }
    return 0;
}
