//
//  main.cpp
//  7
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
#define maxn 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct node{
    int v;
    friend bool operator<(node x,node y){
        return x.v>y.v;
    }
};
int a[maxn];
int n,m;
priority_queue<node> p;
bool check(int x){
    int y=(n-2)/(x-1)+1;
    int z=(n+y-1)%x;
    long long ans=0;
    while(!p.empty())p.pop();
    int i=1;
    for(;i<=z;i++){
        ans+=a[i];
    }
    if(z){
        node t;
        t.v=ans;
        p.push(t);
    }
    while(true){
        int now=0;
        for(int j=1;j<=x;j++){
            if(p.empty()&&i>n){
                break;
            }
            else if(i>n){
                node t=p.top();
                p.pop();
                now+=t.v;
            }
            else if(p.empty()){
                now+=a[i++];
            }
            else {
                node t=p.top();
                if(a[i]<=t.v){
                    now+=a[i++];
                }
                else {
                    p.pop();
                    now+=t.v;
                }
            }
        }
        ans+=now;
        node t;
        t.v=now;
        p.push(t);
        if(p.size()==1&&i>n)break;
    }
    return ans<=m;
}
int main(int argc, const char * argv[]) {
    int i,j,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        int l=1,r=n;
        while(l<r-1){
            int mid=(l+r)>>1;
            if(check(mid))r=mid;
            else l=mid;
        }
        printf("%d\n",r);
    }
    return 0;
}
