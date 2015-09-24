//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/7/30.
//  Copyright (c) 2015骞?wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
//#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 100005
#define P 1000000007
#define INF 2100000000
#define MAX 50050
using namespace std;
typedef long long LL;
int n,m;
LL c[MAX];
LL w[MAX];
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
            tree[p].now += v;
            down(p);
            return;
        }
        down(p);
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid){
            add(l, r, v, 2 * p);
            down(2 * p + 1);
        }
        else if(l > mid){
            add(l, r, v, 2 * p + 1);
            down(2 * p);
        }
        else{
            add(l, mid, v, 2 * p);
            add(mid + 1, r, v, 2 * p + 1);
        }
        tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
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
        if(l == r) tree[p].sum = 0;
        if(l < r){
            int mid = (l + r) >> 1;
            build(l, mid, 2 * p);
            build(mid + 1, r, 2 * p + 1);
            tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
        }
    }
private:
    node tree[4 * MAX];
    void down(int p){
        if(tree[p].now == 0) return;
        if(tree[p].l < tree[p].r){
            tree[2 * p].now += tree[p].now;
            tree[2 * p + 1].now += tree[p].now;
        }
        tree[p].sum += (tree[p].r - tree[p].l + 1) * tree[p].now;
        tree[p].now = 0;
    }
    
};
LL gcd(LL x,LL y) {
    if(x < y) swap(x,y);
    return (x % y == 0) ? y : gcd(y, x % y);
}
SegmentTree tre(1);
int main() {
    int t;cin >> t;
    memset(c,0,sizeof c);
    c[3] = 1;
    for(int i = 4;i <= 50000;i++) {
        c[i] = c[i-1] * i / (i-3);
    }
    LL ans;
    while(t--) {
        ans = 0;
        scanf("%d%d",&n,&m);
        tre.build(1,n);
        for(int i = 1;i <= n;i++) {
            scanf("%I64d",&w[i]);
        }
        for(int i = 1;i <= m;i++) {
            int x,y;scanf("%d%d",&x,&y);
            tre.add(x,y,1);
        }
        for(int i = 1;i <= n;i++) {
            int tmp = tre.query(i,i);
            ans += c[tmp]*w[i];
        }
        LL xx,yy;
        if(ans == 0) {printf("0\n");continue;}
        LL tmp2 = gcd(ans,c[m]);
        xx = ans / tmp2;
        yy = c[m] / tmp2;
        
        if(yy == 1) printf("%I64d\n",xx);
        else printf("%I64d/%I64d\n",xx,yy);
    }
    return 0;
}