//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/5/27.
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
#define maxn 105
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

struct line{
    int x1,x2,y1,y2;
};
line a[maxn];
bool flag[maxn];
bool check(int p,int q){
    double k1,k2,b1,b2,x,y;
    k1=1.0*(a[p].y1-a[p].y2)/(a[p].x1-a[p].x2);
    k2=1.0*(a[q].y1-a[q].y2)/(a[q].x1-a[q].x2);
    b1=a[p].y1-k1*a[p].x1;
    b2=a[q].y1-k2*a[q].x1;
    if(a[p].x1==a[p].x2){
        if(a[q].x1==a[q].x2){
            if(a[p].x1==a[q].x1){
                if((a[p].y1-a[q].y1)*(a[p].y1-a[q].y2)<=0||(a[p].y2-a[q].y1)*(a[p].y2-a[q].y2)<=0||(a[p].y1-a[q].y1)*(a[p].y2-a[q].y1)<=0||(a[p].y1-a[q].y2)*(a[p].y2-a[q].y2)<=0)return true;
                else return false;
            }
            else return false;
        }
        else {
            x=a[p].x1;
            y=k2*x+b2;
            if((a[q].y1-y)*(a[q].y2-y)<0.0001&&(a[p].y1-y)*(a[p].y2-y)<0.0001)return true;
            else return false;
        }
    }
    else if(a[q].x1==a[q].x2){
        x=a[q].x1;
        y=k1*x+b1;
        if((a[q].y1-y)*(a[q].y2-y)<0.0001&&(a[p].y1-y)*(a[p].y2-y)<0.0001)return true;
        else return false;
    }
    x=(b2-b1)/(k1-k2);
    //printf("%lf %lf %lf %lf %lf %lf\n",k1,k2,b1,b2,x,y);
    if((a[p].x1-x)*(a[p].x2-x)<0&&(a[q].x1-x)*(a[q].x2-x)<0)return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        }
        memset(flag,0,sizeof(flag));
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(check(i,j)){
                    flag[i]=true;
                    break;
                }
            }
        }
        bool z=0;
        for(i=1;i<=n;i++){
            if(!flag[i]){
                if(z){
                    printf(" %d",i);
                }
                else printf("%d",i);
                z=1;
            }
        }
        printf("\n");
    }
    return 0;
}
