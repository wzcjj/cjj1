//
//  main.cpp
//  12
//
//  Created by wzcjj on 16/8/2.
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
#define maxn 50005
#define P 1000000007
#define INF 1000000006
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct node{
    int a,b,c,d,v;
};
node a[maxn],b[maxn],c[maxn];
void sortt(int l,int r){
    if(l>=r)return;
    int mid=(l+r)>>1,i,j;
    sortt(l,mid);
    sortt(mid+1,r);
    for(i=1;i<=mid-l+1;i++)b[i]=a[l+i-1];
    for(j=1;j<=r-mid;j++)c[j]=a[mid+j];
    b[mid-l+2].v=c[r-mid+1].v=INF;
    i=j=1;
    while(i<=mid-l+1||j<=r-mid){
        if(b[i].v<c[j].v){
            a[i+j-2+l]=b[i];
            a[i+j-2+l].d+=j-1;
            a[i+j-2+l].b+=r-mid-j+1;
            i++;
        }
        else if(b[i].v>c[j].v){
            a[i+j-2+l]=c[j];
            a[i+j-2+l].a+=i-1;
            a[i+j-2+l].c+=mid-l+1-i+1;
            j++;
        }
        else {
            int k=i,p=j;
            while(b[k].v==b[k+1].v)k++;
            while(c[p].v==c[p+1].v)p++;
            for(int o=i;o<=k;o++){
                b[o].d+=j-1;
                b[o].b+=r-mid-p;
                a[o+j-2+l]=b[o];
            }
            for(int o=j;o<=p;o++){
                c[o].a+=i-1;
                c[o].c+=mid-l+1-k;
                a[o+k-1+l]=c[o];
            }
            i=k+1;
            j=p+1;
        }
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d",&n)!=EOF) {
        memset(a, 0, sizeof(a));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i].v);
        }
        sortt(1,n);
        long long x=0,y=0,ans=0;
        for(i=1;i<=n;i++){
            x+=a[i].a+a[i].b;
            y+=a[i].c+a[i].d;
            ans-=(a[i].a+a[i].b)*(a[i].d+a[i].c);
        }
        ans+=x*y/4;
        printf("%lld\n",ans);
    }
    return 0;
}
