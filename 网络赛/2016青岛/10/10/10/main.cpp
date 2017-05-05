//
//  main.cpp
//  10
//
//  Created by wzcjj on 16/9/17.
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
#define maxn 105
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct node{
    int c,v;
};
node a[maxn];
bool cmp(node x,node y){
    return x.v>y.v;
}
bool cmp1(node x,node y){
    return x.c<y.c;
}
bool cmp2(node x,node y){
    return x.c>y.c;
}
bool cmp3(node x,node y){
    return 1.0*x.v/x.c>1.0*y.v/y.c;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d%d",&n,&m)!=EOF) {
        for(i=0;i<n;i++){
            scanf("%d%d",&a[i].c,&a[i].v);
        }
        if(n<=27){
            long long maxx=0;
            for(i=0;i<(1<<n);i++){
                long long sum=0,cost=0;
                for(j=0;j<n;j++)if(i&(1<<j)){
                    cost+=a[j].c;
                    sum+=a[j].v;
                }
                if(cost<=m&&maxx<sum)maxx=sum;
            }
            printf("%lld\n",maxx);
        }
        else {
            sort(a,a+n,cmp);
            long long cost=0,sum=0,maxx=0;
            for(i=0;i<n;i++){
                if(cost+a[i].c<=m){
                    cost+=a[i].c;
                    sum+=a[i].v;
                }
            }
            if(sum>maxx)maxx=sum;
            sort(a,a+n,cmp1);
            cost=0,sum=0;
            for(i=0;i<n;i++){
                if(cost+a[i].c<=m){
                    cost+=a[i].c;
                    sum+=a[i].v;
                }
            }
            if(sum>maxx)maxx=sum;
            sort(a,a+n,cmp2);
            cost=0,sum=0;
            for(i=0;i<n;i++){
                if(cost+a[i].c<=m){
                    cost+=a[i].c;
                    sum+=a[i].v;
                }
            }
            if(sum>maxx)maxx=sum;
            sort(a,a+n,cmp3);
            cost=0,sum=0;
            for(i=0;i<n;i++){
                if(cost+a[i].c<=m){
                    cost+=a[i].c;
                    sum+=a[i].v;
                }
            }
            if(sum>maxx)maxx=sum;
            printf("%lld\n",maxx);
        }
    }
    return 0;
}
