//
//  main.cpp
//  4
//
//  Created by wzcjj on 16/7/19.
//  Copyright (c) 2016年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;
int a[maxn];
int gcd(int x,int y){
    if(y==0)return x;
    return gcd(y,x%y);
}
class SegmentTree
{
public:
    struct node{
        int l, r;
        int gcd;
    };
    
    int query(int l,int r,int p = 1){
        if(l == tree[p].l && r == tree[p].r)return tree[p].gcd;
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid)return query(l, r, 2 * p);
        else if(l > mid)return query(l, r, 2 * p + 1);
        else return gcd(query(l, mid, 2 * p), query(mid + 1, r, 2 * p + 1));
    }
    
    void build(int l,int r,int p = 1){
        tree[p].l = l;
        tree[p].r = r;
        if(l == r) {
            tree[p].gcd = a[l];
        }
        if(l < r){
            int mid = (l + r) >> 1;
            build(l, mid, 2 * p);
            build(mid + 1, r, 2 * p + 1);
            tree[p].gcd = gcd(tree[2 * p].gcd, tree[2 * p + 1].gcd);
        }
    }
private:
    node tree[4 * maxn];
};
SegmentTree tre;
map<int,long long>ma;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I;
    cin>>N;
    while(N--){
        I++;
        printf("Case #%d:\n",I);
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        ma.clear();
        tre.build(1, n);
        for(i=1;i<=n;i++){
            /*int l=i,r=n+1;
            while(l<r-1){
                int mid=(l+r)>>1;
                if(tre.query(i, mid)==1)r=mid;
                else l=mid;
            }
            int nn=l;
            ma[1]+=n-nn;*/
            //if(nn-i>5){
                for(j=n;j>=i;j--){
                    int ij=tre.query(i, j);
                    int l=i-1,r=j+1;
                    while(l<r-1){
                        int mid=(l+r)>>1;
                        int now=tre.query(i, mid);
                        if(ij!=now)l=mid;
                        else r=mid;
                    }
                    ma[ij]+=j-l;
                    j=r;
                }
            //}
            /*else {
                for(j=i;j<=nn;j++){
                    
                }
            }*/
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int ans=tre.query(x, y);
            printf("%d %lld\n",ans,ma[ans]);
        }
    }
    return 0;
}