//
//  main.cpp
//  8
//
//  Created by wzcjj on 15/8/6.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;

struct node{
    int l,r,i;
    friend bool operator<(node x,node y){
        if(x.r<y.r)return true;
        if(x.r>y.r)return false;
        return x.l<y.l;
    }
}a[maxn];
vector<node> b[maxn];
multiset<node> c;
vector<int> ou;
bool fl[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=0;i<=n;i++)b[i].clear();
        memset(fl, 0, sizeof(fl));
        ou.clear();
        c.clear();
        for(i=1;i<=n;i++)scanf("%d",&a[i].l);
        for(i=1;i<=n;i++)scanf("%d",&a[i].r);
        for(i=1;i<=n;i++)a[i].i=i;
        for(i=1;i<=n;i++)b[a[i].l].push_back(a[i]);
        for(i=0;i<n;i++){
            for(j=0;j<b[i].size();j++)c.insert(b[i][j]);
            if(c.empty())break;
            bool flag=false;
            while(true){
                if(c.empty()){
                    flag=true;
                    break;
                }
                node t=*c.begin();
                if(t.r<i){
                    c.erase(c.begin());
                    continue;
                }
                ou.push_back(t.i);
                c.erase(c.begin());
                break;
            }
            if(flag)break;
        }
        printf("%d\n",ou.size());
        if(ou.size()==n){
            for(i=0;i<ou.size()-1;i++)printf("%d ",ou[i]);
            printf("%d\n",ou[ou.size()-1]);
        }
        else {
            for(i=1;i<ou.size();i++){
                printf("%d ",ou[i-1]);
                fl[ou[i-1]]=true;
            }
            for(i=1;i<=n;i++)if(!fl[i]){
                printf("%d",i);
                break;
            }
            for(i=i+1;i<=n;i++){
                printf(" %d",i);
            }
            printf("\n");
        }
    }
    return 0;
}
