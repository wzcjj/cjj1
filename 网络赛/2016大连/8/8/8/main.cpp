//
//  main.cpp
//  8
//
//  Created by wzcjj on 16/9/10.
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
#define maxn 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct node{
    int i,v,l,r;
    friend bool operator<(node x,node y){
        return x.v>y.v;
    }
};
int a[maxn];
node b[maxn];
int ans[maxn];
multiset<node> s;
bool cmp(node x,node y){
    return x.l<y.l;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    b[0].i=0;
    b[0].v=INF;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            b[i].l=x;b[i].r=y;
            b[i].i=i;b[i].v=a[x];
        }
        sort(b+1,b+1+m,cmp);
        s.clear();
        int k=1;
        for(i=1;i<=n+1;i++){
            for(multiset<node>::iterator j1,j=s.begin();j!=s.end();j=j1){
                if((*j).r<i){
                    ans[(*j).i]=(*j).v;
                    j1=j;
                    j1++;
                    s.erase(j);
                }
                else if((*j).v>=a[i]){
                    node t=*j;
                    j1=j;
                    j1++;
                    s.erase(j);
                    t.v%=a[i];
                    s.insert(t);
                }
                else {
                    break;
                }
            }
            while(k<=m&&b[k].l==i){
                s.insert(b[k]);
                k++;
            }
        }
        for(i=1;i<=m;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
