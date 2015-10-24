//
//  main.cpp
//  8
//
//  Created by wzcjj on 15/9/26.
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
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;


int a[maxn],m;
class SegmentTree
{
public:
    struct node{
        int l, r;
        long long now, sum;
    };
    
    SegmentTree(int size){
        build(1, size);
    }
    
    void add(int l,int r,int v,int p = 1){
        if(l == tree[p].l && r == tree[p].r){
            tree[p].sum = v;
            return;
        }
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid){
            add(l, r, v, 2 * p);
        }
        else if(l > mid){
            add(l, r, v, 2 * p + 1);
        }
        else{
            add(l, mid, v, 2 * p);
            add(mid + 1, r, v, 2 * p + 1);
        }
        tree[p].sum = (tree[2 * p].sum * tree[2 * p + 1].sum) % m;
    }
    
    long long query(int l,int r,int p = 1){
        down(p);
        if(l == tree[p].l && r == tree[p].r)return tree[p].sum;
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid)return query(l, r, 2 * p);
        else if(l > mid)return query(l, r, 2 * p + 1);
        else return query(l, mid, 2 * p) + query(mid + 1, r, 2 * p + 1);
    }
    void build(int l,int r,int p = 1){
        tree[p].l = l;
        tree[p].r = r;
        tree[p].now = 0;
        if(l == r) tree[p].sum = 1;
        if(l < r){
            int mid = (l + r) >> 1;
            build(l, mid, 2 * p);
            build(mid + 1, r, 2 * p + 1);
            tree[p].sum = (tree[2 * p].sum * tree[2 * p + 1].sum) % m;
        }
    }
private:
    node tree[4 * maxn];
    void down(int p){
        if(tree[p].now == 0) return;
        if(tree[p].l < tree[p].r){
            tree[2 * p].now += tree[p].now;
            tree[2 * p + 1].now += tree[p].now;
        }
        tree[p].sum *= (tree[p].r - tree[p].l + 1) * tree[p].now;
        tree[p].now = 0;
    }
};
SegmentTree b(1);
int main(int argc, const char * argv[]) {
    int i,j,n,N;
    cin>>N;
    int I=0;
    while (N--) {
        I++;
        printf("Case #%d:\n",I);
        scanf("%d%d",&n,&m);
        b.build(1, n);
        for(i=1;i<=n;i++){
            int x;
            scanf("%d%d",&x,&a[i]);
            if(x==1){
                b.add(i, i, a[i]);
                printf("%lld\n",b.query(1, n));
            }
            else{
                b.add(a[i],a[i],1);
                printf("%lld\n",b.query(1, n));
            }
        }
    }
    return 0;
}
