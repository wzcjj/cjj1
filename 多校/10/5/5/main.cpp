//
//  main.cpp
//  5
//
//  Created by wzcjj on 16/8/18.
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
#define maxn 200005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct node{
    int l,r;
};
int a[maxn];
node b[maxn];
long long c[maxn];
#define RETURN_TYPE int
class SegmentTree
{
public:
    struct node{
        int l, r;
        RETURN_TYPE nowmodify, sum;
    };
    
    void modify(int l,int r,RETURN_TYPE v,int p = 1){ //区间修改
        if(l == tree[p].l && r == tree[p].r){
            tree[p].nowmodify = v;
            return;
        }
        downmodify(p);
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid){
            modify(l, r, v, 2 * p);
            downmodify(2 * p + 1);
        }
        else if(l > mid){
            modify(l, r, v, 2 * p + 1);
            downmodify(2 * p);
        }
        else{
            modify(l, mid, v, 2 * p);
            modify(mid + 1, r, v, 2 * p + 1);
        }
        up(p);
    }
    
    RETURN_TYPE querysum(int l,int r,int p = 1){
        down(p);
        if(l == tree[p].l && r == tree[p].r)return tree[p].sum;
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid)return querysum(l, r, 2 * p);
        else if(l > mid)return querysum(l, r, 2 * p + 1);
        else return (querysum(l, mid, 2 * p) + querysum(mid + 1, r, 2 * p + 1));
    }
    
    void build(int l,int r,int p = 1){//输入1~n
        tree[p].l = l;
        tree[p].r = r;
        tree[p].nowmodify = -INF;
        if(l == r) {
            tree[p].sum = 0;
        }
        if(l < r){
            int mid = (l + r) >> 1;
            build(l, mid, 2 * p);
            build(mid + 1, r, 2 * p + 1);
            tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
        }
    }
private:
    node tree[8 * maxn];
    
    void downmodify(int p){
        if(tree[p].nowmodify == -INF)return;
        if(tree[p].l < tree[p].r){
            tree[2 * p].nowmodify = tree[p].nowmodify;
            tree[2 * p + 1].nowmodify = tree[p].nowmodify;
        }
        tree[p].sum = (tree[p].r - tree[p].l + 1) * tree[p].nowmodify;
        tree[p].nowmodify = -INF;
    }
    
    void down(int p){
        downmodify(p);
    }
    
    void up(int p){
        tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
    }
};
SegmentTree seg1,seg2;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d%d",&n,&m)!=EOF) {
        for(i=1;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d%d",&b[i].l,&b[i].r);
            if(b[i].l>b[i].r){
                int t=b[i].l;
                b[i].l=b[i].r;
                b[i].r=t;
            }
        }
        memset(c, 0, sizeof(c));
        seg1.build(1, n-1);
        seg2.build(1, n-1);
        for(i=1;i<=m;i++){
            seg2.modify(b[i].l, b[i].r-1, i);
        }
        for(i=m;i>=1;i--){
            seg1.modify(b[i].l, b[i].r-1, i);
        }
        for(i=1;i<n;i++){
            c[seg1.querysum(i, i)]+=a[i];
            c[seg2.querysum(i, i)+1]-=a[i];
        }
        long long sum=0;
        for(i=0;i<=m;i++){
            sum+=c[i];
            c[i]=sum;
        }
        for(i=1;i<=m;i++){
            printf("%lld\n",c[i]);
        }
    }
    return 0;
}
