//
//  main.cpp
//  hdu1166
//
//  Created by wzcjj on 15/8/5.
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
#define maxn 50005
#define P 1000000007
#define INF 2100000000
using namespace std;

class BIT{
public:
    int bit[maxn],size;
    BIT(int size){
        this->size = size;
        memset(bit,0,sizeof(bit));
    }
    int lowbit(int x){
        return x&(-x);
    }
    void add(int x,int v){
        while(x<=size){
            bit[x]+=v;
            x+=lowbit(x);
        }
    }
    int query(int x){
        int sum=0;
        while(x>0){
            sum+=bit[x];
            x-=lowbit(x);
        }
        return sum;
    }
};
int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    for (int I=1; I<=N; I++) {
        printf("Case %d:\n",I);
        scanf("%d",&n);
        BIT bi(n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)bi.add(i,a[i]);
        char s[10];
        scanf("%s",s);
        while(strcmp(s, "End")!=0){
            if (strcmp(s, "Query")==0) {
                scanf("%d%d",&i,&j);
                printf("%d\n",bi.query(j)-bi.query(i-1));
            }
            else if(strcmp(s, "Add")==0){
                scanf("%d%d",&i,&j);
                bi.add(i, j);
            }
            else{
                scanf("%d%d",&i,&j);
                bi.add(i, -j);
            }
            scanf("%s",s);
        }
    }
    return 0;
}