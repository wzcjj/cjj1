//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/7/30.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;
int a[maxn];
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

    SegmentTree(){
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
        if(l == r) tree[p].sum = a[l];
        if(l < r){
            int mid = (l + r) >> 1;
            build(l, mid, 2 * p);
            build(mid + 1, r, 2 * p + 1);
            tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
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
        tree[p].sum += (tree[p].r - tree[p].l + 1) * tree[p].now;
        tree[p].now = 0;
    }
};

int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    scanf("%d",&N);
    while(N--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        SegmentTree tre(n);
        for(i=1;i<=m;i++){
            char c[1];
            scanf("%s",c);
            if(c[0]=='Q'){
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%lld\n",tre.query(x,y));
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
