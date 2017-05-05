//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/4/8.
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
#define eps 0.000001
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

struct node {
    int x,y,v;
};
node a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n;
    while (true) {
        scanf("%d",&n);
        if(n==0)break;
        for(i=1;i<=n;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
            a[i].v=1;
        }
        int ans=2;
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(a[i].x==a[j].x){
                    if(a[i].y==a[j].y){
                        a[i].v++;
                        a[j].v--;
                    }
                    int cnt=a[i].v+a[j].v;
                    for(int l=j+1;l<=n;l++)if(a[l].x==a[i].x)cnt+=a[l].v;
                }
                else {
                    double k=(a[i].y-a[j].y)*1.0/(a[i].x-a[j].x),b=a[i].y-k*a[i].x;
                    int cnt=a[i].v+a[j].v;
                    for(int l=j+1;l<=n;l++){
                        if(abs(a[l].y-a[l].x*k-b)<eps)cnt+=a[l].v;
                    }
                    if(cnt>ans)ans=cnt;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
