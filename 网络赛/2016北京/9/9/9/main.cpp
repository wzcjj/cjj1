//
//  main.cpp
//  9
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
#define maxn 10005
#define P 1000000007
#define INF 2000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct node {
    long long s,c,d;
};
struct node1{
    long long t,d;
    friend bool operator<(node1 x,node1 y){
        return x.t<y.t;
    }
};
node a[maxn],b[maxn];
long long c[10*maxn];
multiset<node1> s;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    long long ta,tb,st;
    while (scanf("%lld%lld",&ta,&tb)!=EOF) {
        scanf("%lld",&st);
        scanf("%d%d",&n,&m);
        s.clear();
        long long sum=0;
        memset(c, 0, sizeof(c));
        for(i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i].s,&a[i].c,&a[i].d);
        }
        for(i=1;i<=m;i++){
            scanf("%lld%lld%lld",&b[i].s,&b[i].c,&b[i].d);
        }
        for(i=1;i<=n;i++){
            if(a[i].s+a[i].c<=tb+st&&a[i].s+a[i].c>=st){
                if(a[i].s+2*a[i].c>=(tb+st-(a[i].s+a[i].c))/(2*a[i].c)*(2*a[i].c)+(a[i].s+2*a[i].c)-ta){
                    node1 t;
                    t.t=a[i].s+2*a[i].c+1;
                    t.d=-a[i].d;
                    s.insert(t);
                    t.t=(tb+st-(a[i].s+a[i].c))/(2*a[i].c)*(2*a[i].c)+(a[i].s+2*a[i].c)-ta;
                    t.d=a[i].d;
                    s.insert(t);
                }
                sum+=a[i].d;
            }
        }
        for(i=1;i<=m;i++){
            if(b[i].s+2*b[i].c<st||b[i].s+2*b[i].c>st+tb){
                node1 t;
                t.t=b[i].s+b[i].c+1;
                t.d=-b[i].d;
                s.insert(t);
                t.t=b[i].s+b[i].c-ta;
                t.d=b[i].d;
                s.insert(t);
            }
            else if(b[i].s+b[i].c>=(tb+st-(b[i].s))/(2*b[i].c)*(2*b[i].c)+(b[i].s+b[i].c)-ta){
                node1 t;
                t.t=b[i].s+b[i].c+1;
                t.d=-b[i].d;
                s.insert(t);
                t.t=(tb+st-(b[i].s))/(2*b[i].c)*(2*b[i].c)+(b[i].s+b[i].c)-ta;
                t.d=b[i].d;
                s.insert(t);
            }
            sum+=b[i].d;
        }
        long long now=-INF,cnt=0;
        for(multiset<node1>::iterator it=s.begin();it!=s.end();it++){
            if((*it).t!=now){
                now=(*it).t;
                cnt++;
            }
            c[cnt]+=(*it).d;
        }
        long long maxx=0,summ=0;
        for(i=1;i<=cnt;i++){
            summ+=c[i];
            if(maxx<summ)maxx=summ;
        }
        printf("%lld\n",sum-maxx);
    }
    return 0;
}
