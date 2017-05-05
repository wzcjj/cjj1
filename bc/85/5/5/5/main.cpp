//
//  main.cpp
//  5
//
//  Created by wzcjj on 16/7/30.
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
#define maxn 1000005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

//vector<int> a[maxn];
int b[maxn];
long long c[maxn];
long long d[maxn];
bool flag[maxn];
int pow(int x,int y){
    long long t=1,s=x;
    for(int i=0;(1<<i)<=y;i++){
        if((1<<i)&y){
            t=t*s%P;
        }
        s=s*s%P;
    }
    return t;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n=1000000,N;
    //memset(flag,0,sizeof(flag));
    for(i=1;i<=n;i++)b[i]=i;
    //long long asd=0;
    for(i=2;i<=n;i++)if(!flag[i]){
        for(j=1;j*i<=n;j++){
            flag[i*j]=true;
            b[i*j]-=b[i*j]/i;
            //asd++;
            //a[j*i].push_back(i);
        }
    }
    //cout<<asd<<endl;
    /*for(i=2;i<=n;i++){
        b[i]=i;
        for(j=0;j<a[i].size();j++){
            b[i]-=b[i]/a[i][j];
        }
        for(j=0;j<(1<<a[i].size());j++){
            int sum=1,cnt=0;
            for(int k=0;k<a[i].size();k++){
                if((1<<k)&j){
                    cnt++;
                    sum*=a[i][k];
                }
            }
            if(cnt&1)b[i]-=i/sum;
            else b[i]+=i/sum;
        }
    }*/
    c[1]=1;
    for(i=2;i<=n;i++){
        c[i]=c[i-1]+2*b[i];
    }
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        d[1]=n;
        for(i=2;i<=m;i++)d[i]=d[i-1]*n%P;
        int ni=pow(n-1,P-1);
        long long ans=0;
        for(i=1;i<=m;i++){
            ans=(ans+c[m/i]*(d[i]-1)%P*ni)%P;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
