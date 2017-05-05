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

long long a[maxn],b[maxn];
const long double PI = 3.14159265358979323846264338327950288419716939937510;
struct comp
{
    long double r,i;
    comp(long double _r = 0.0,long double _i = 0.0)
    {
        r = _r; i = _i;
    }
    comp operator +(const comp &b)
    {
        return comp(r+b.r,i+b.i);
    }
    comp operator -(const comp &b)
    {
        return comp(r-b.r,i-b.i);
    }
    comp operator *(const comp &b)
    {
        return comp(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
comp c[maxn],d[maxn],e[maxn],f[maxn];
void change(comp y[],int len)
{
    int i,j,k;
    for(i = 1, j = len/2;i < len-1; i++)
    {
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k)
        {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}
void fft(comp *y,int len,int on=1)
{
    change(y,len);
    for(int h = 2; h <= len; h <<= 1)
    {
        comp wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j+=h)
        {
            comp w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                comp u = y[k];
                comp t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
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
            c[i]=comp(a[i+1],0);
            d[i]=comp(b[n-i],0);
        }
        for(i=n;i<len;i++){
            c[i]=d[i]=comp(0,0);
        }
        fft(c, len);
        fft(d, len);
        for(i=0;i<len;i++)e[i]=c[i]*d[i];
        fft(e,len,-1);
        for(i=0;i<n;i++){
            c[i]=comp(a[n-i],0);
            d[i]=comp(b[i+1],0);
        }
        for(i=n;i<len;i++){
            c[i]=d[i]=comp(0,0);
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
            if(maxx*0.999999<(long long)(e[i-1].r+0.5)+(long long)(f[(n-i)-1].r+0.5)){
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
