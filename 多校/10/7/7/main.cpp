//
//  main.cpp
//  7
//
//  Created by wzcjj on 16/8/18.
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
#define maxn 25
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct matrix{
    int n;
    long long a[maxn][maxn];
    friend matrix operator*(matrix x,matrix y){
        matrix t;
        t.n=x.n;
        for(int i=0;i<x.n;i++){
            for(int j=0;j<x.n;j++){
                t.a[i][j]=0;
                for(int k=0;k<x.n;k++){
                    t.a[i][j]=(t.a[i][j]+x.a[i][k]*y.a[k][j])%P;
                }
            }
        }
        return t;
    }
}a,b,c;

matrix pow(matrix x,int y){
    matrix t;
    t.n=x.n;
    memset(t.a, 0, sizeof(t.a));
    for(int i=0;i<x.n;i++)t.a[i][i]=1;
    for(int i=0;(1<<i)<=y;i++){
        if((1<<i)&y){
            t=t*x;
        }
        x=x*x;
    }
    return t;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k;
    cin>>N;
    while (N--) {
        scanf("%d%d%d",&n,&m,&k);
        memset(a.a, 0, sizeof(a.a));
        memset(b.a, 0, sizeof(b.a));
        a.n=2*m+1;
        b.n=2*m+1;
        a.a[0][0]=1;
        for(i=0;i<=2*m;i++){
            if(i<m){
                b.a[i][0]=k*k-k;
                b.a[i][i==m-1?2*m:i+1]=k;
            }
            else {
                b.a[i][m]=k*k-k;
                if(i!=2*m){
                    b.a[i][i+1]=k;
                }
            }
        }
        c=a*pow(b,n);
        long long ans=0;
        for(i=m;i<=2*m;i++){
            ans+=c.a[0][i];
        }
        ans%=P;
        printf("%lld\n",ans);
        /*a[0]=1;
        for(i=1;i<=n;i++){
            for(j=0;j<=m;j++){
                if(i==j){
                    a[i]+=pow(k,j);
                    break;
                }
                a[i]+=a[i-1-j]*(k*(k-1))%P*pow(k,j)%P;
            }
            a[i]%=P;
        }
        long long ans=a[n];
        memset(a, 0, sizeof(a));
        a[0]=1;
        for(i=1;i<=n;i++){
            for(j=0;j<m;j++){
                if(i==j){
                    a[i]+=pow(k,j);
                    break;
                }
                a[i]+=a[i-1-j]*(k*(k-1))%P*pow(k,j)%P;
            }
            a[i]%=P;
        }
        printf("%lld\n",(ans-a[n]+P)%P);*/
    }
    return 0;
}
