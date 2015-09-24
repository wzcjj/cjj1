//
//  main.cpp
//  3
//
//  Created by wzcjj on 15/8/27.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
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
#define INF 3100000000LL
using namespace std;

struct node{
    int a,b,c;
}d[maxn];
int n;
long long check(long long x){
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(d[i].a<=x){
            if(d[i].b<=x){
                ans+=(d[i].b-d[i].a)/d[i].c+1;
            }
            else{
                ans+=(x-d[i].a)/d[i].c+1;
            }
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    int i,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
        }
        long long l=-1,r=INF,mid;
        while(l<r-1){
            mid=(l+r)>>1;
            if((check(mid)&1))r=mid;
            else l=mid;
        }
        if(r==INF)puts("Poor QIN Teng:(");
        else if(r==0)cout<<r<<' '<<check(0)<<endl;
        else cout<<r<<' '<<check(r)-check(l)<<endl;
    }
    return 0;
}
