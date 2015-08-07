//
//  main.cpp
//  hdu1754
//
//  Created by wzcjj on 15/8/5.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 200005
#define P 1000000007
#define INF 2100000000
using namespace std;
int a[maxn];
int max(int x,int y){
    return x>y?x:y;
}
class SegmentTree
{
public:
    struct node{
        int l, r;
        int now, maxx;
    };
    
    SegmentTree(int size){
        build(1, size);
    }
    
    void add(int l,int r,int v,int p = 1){
        if(l == tree[p].l && r == tree[p].r){
            tree[p].now = v;
            tree[p].maxx = v;
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
        tree[p].maxx = max(tree[2 * p].maxx, tree[2 * p + 1].maxx);
    }
    
    int query(int l,int r,int p = 1){
        down(p);
        if(l == tree[p].l && r == tree[p].r)return tree[p].maxx;
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid)return query(l, r, 2 * p);
        else if(l > mid)return query(l, r, 2 * p + 1);
        else return max(query(l, mid, 2 * p), query(mid + 1, r, 2 * p + 1));
    }
private:
    node tree[4 * maxn];
    void down(int p){
        if(tree[p].now==-INF)return;
        if(tree[p].l < tree[p].r){
            tree[2 * p].now = tree[p].now;
            tree[2 * p + 1].now = tree[p].now;
        }
        tree[p].maxx = tree[p].now;
        tree[p].now = -INF;
    }
    void build(int l,int r,int p = 1){
        tree[p].l = l;
        tree[p].r = r;
        tree[p].now = -INF;
        if(l == r) tree[p].maxx = a[l];
        if(l < r){
            int mid = (l + r) >> 1;
            build(l, mid, 2 * p);
            build(mid + 1, r, 2 * p + 1);
            tree[p].maxx = max(tree[2 * p].maxx, tree[2 * p + 1].maxx);
        }
    }
};

int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        SegmentTree tre(n);
        for(i=1;i<=m;i++){
            char c[5];
            scanf("%s",c);
            if(c[0]=='Q'){
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",tre.query(x,y));
            }
            else{
                int x,y,z;
                scanf("%d%d%d",&x,&y,&z);
                tre.add(x,y,z);
            }
        }
    }
    return 0;
}