//
//  main.cpp
//  3
//
//  Created by wzcjj on 15/8/21.
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
#define P 10000
#define INF 2100000000
using namespace std;

class Martix{
    public:
    int a[5][5],x,y;
    friend Martix operator*(Martix p,Martix q){
        Martix t;
        int i,j,k;
        t.x=t.y=2;
        for(i=1;i<=p.x;i++){
            for(j=1;j<=q.y;j++){
                t.a[i][j]=0;
                for(k=1;k<=p.y;k++){
                    t.a[i][j]=(t.a[i][j]+p.a[i][k]*q.a[k][j])%P;
                }
            }
        }
        return t;
    }
};
Martix a[40];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    a[0].a[1][1]=a[0].a[1][2]=a[0].a[2][1]=1;
    a[0].a[2][2]=0;
    a[0].x=a[0].y=2;
    for(i=1;i<=35;i++){
        a[i]=a[i-1]*a[i-1];
        a[i].x=a[i].y=2;
    }
    for(scanf("%d",&n);n!=-1;scanf("%d",&n)) {
        i=0;
        Martix ans;
        ans.x=ans.y=2;
        ans.a[1][1]=ans.a[2][2]=1;
        ans.a[1][2]=ans.a[2][1]=0;
        while(n){
            if(n&(1<<i)){
                ans=ans*a[i];
                n-=(1<<i);
            }
            i++;
        }
        printf("%d\n",ans.a[1][2]);
    }
    return 0;
}
