//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/8/4.
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
#define maxn 10005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct martix{
    long long a[2][2];
    friend martix operator*(martix a, martix b){
        martix t;
        int n=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                t.a[i][j]=0;
                for(int k=0;k<n;k++){
                    t.a[i][j]=(t.a[i][j]+a.a[i][k]*b.a[k][j])%P;
                }
            }
        }
        return t;
    }
};
/*long long a[maxn];
int b[maxn];
long long c[30][30];
long long ans;
void dfs(int x,int n,int m){
    if(x>m){
        long long sum=a[b[m]]/a[b[1]];
        for(int i=1;i<m;i++){
            sum/=a[b[i+1]-b[i]];
        }
        ans+=sum;
        return;
    }
    for(int i=b[x-1];i<=n;i++){
        b[x]=i;
        dfs(x+1,n,m);
    }
}*/
int main(int argc, const char * argv[]) {
    int i,j,N,n=10,m=5;
    /*a[0]=1;
    b[0]=0;
    c[0][0]=-1;
    for(i=1;i<=n;i++)a[i]=a[i-1]*i%P;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            ans=0;
            dfs(1,i,j);
            printf("%lld ",ans);
        }
        printf("\n");
    }*/
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        martix a,b;
        b.a[0][1]=a.a[1][0]=0;
        a.a[0][0]=a.a[1][1]=a.a[0][1]=b.a[1][0]=b.a[1][1]=1;
        b.a[0][0]=m;
        for(i=0;(1<<i)<=n;i++){
            if((1<<i)&n){
                a=a*b;
            }
            b=b*b;
        }
        printf("%lld\n",a.a[0][0]);
    }
    return 0;
}
