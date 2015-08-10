//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/8/8.
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
#define maxn 10005
#define P 1000000007
#define INF 2100000000
using namespace std;
int sqr(int x){
    return x*x;
}
struct node{
    int x, y;
}a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,k,l;
    while (scanf("%d",&n)!=EOF) {
        for(i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
        int ans=0;
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                for(k=j+1;k<=n;k++){
                    for(l=k+1;l<=n;l++){
                        if(sqr(a[l].x-a[k].x)+sqr(a[l].y-a[k].y)==sqr(a[j].x-a[i].x)+sqr(a[j].y-a[i].y)&&sqr(a[l].x-a[j].x)+sqr(a[l].y-a[j].y)==sqr(a[k].x-a[i].x)+sqr(a[k].y-a[i].y)&&sqr(a[l].x-a[i].x)+sqr(a[l].y-a[i].y)==sqr(a[j].x-a[k].x)+sqr(a[j].y-a[k].y)&&(sqr(a[l].x-a[k].x)+sqr(a[l].y-a[k].y)==sqr(a[l].x-a[i].x)+sqr(a[l].y-a[i].y)||sqr(a[l].x-a[k].x)+sqr(a[l].y-a[k].y)==sqr(a[j].x-a[l].x)+sqr(a[j].y-a[l].y)||sqr(a[l].x-a[j].x)+sqr(a[l].y-a[j].y)==sqr(a[l].x-a[i].x)+sqr(a[l].y-a[i].y)))ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
