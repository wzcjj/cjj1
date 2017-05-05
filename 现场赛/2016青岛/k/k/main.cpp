//
//  main.cpp
//  k
//
//  Created by wzcjj on 2016/11/19.
//  Copyright © 2016年 wzcjj. All rights reserved.
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
#define maxn 200005
#define P 1000000007
#define INFL 10000000000000000LL
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;
#define BUFSIZE 80000000
//char buf[BUFSIZE], *pt = buf;
#define scan(t) do { \
t = 0; \
while (!((*pt) >= '0' && (*pt) <= '9')) pt ++; \
while (((*pt) >= '0' && (*pt) <= '9')) t = t * 10 + (*(pt ++)) - '0'; \
} while (0)
struct node{
    long long x,y,c;
};
node a[maxn];
int b[maxn];
inline bool cmp(int x,int y){
    return a[x].c<a[y].c;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    //fread(buf, 1, BUFSIZE, stdin);
    cin>>N;
    //scan(N);
    while (N--) {
        //scan(n);scan(m);
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            //scan(a[i].x);scan(a[i].y);scan(a[i].c);
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].c);
            //a[i].i=i;
            b[i]=i;
        }
        sort(b+1,b+1+n,cmp);
        for(i=1;i<=m;i++){
            //node ans;
            long long x,y,c;
            //scan(x);scan(y);scan(c);
            scanf("%lld%lld%lld",&x,&y,&c);
            long long r=INFL,ii=0,iii=0;
            for(j=1;j<=n;j++){
                if(a[b[j]].c>c)break;
                long long t=(x-a[b[j]].x)*(x-a[b[j]].x)+(y-a[b[j]].y)*(y-a[b[j]].y);
                if(t<r||(t==r&&b[j]<ii)){
                    r=t;
                    ii=b[j];
                    iii=j;
                }
            }
            printf("%lld %lld %lld\n",a[b[iii]].x,a[b[iii]].y,a[b[iii]].c);
        }
    }
    return 0;
}
