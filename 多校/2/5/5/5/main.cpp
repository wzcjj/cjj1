//
//  main.cpp
//  5
//
//  Created by wzcjj on 16/7/21.
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
#define maxn 10005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct node{
    int x,y,num;
    double k;
};
node a[maxn];
void swap(node &x,node &y){
    node t=x;
    x=y;
    y=t;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                while(a[i].x==a[j].x&&a[i].y==a[j].y){
                    a[i].num++;
                    swap(a[n],a[j]);
                    n--;
                }
            }
        }
    }
    return 0;
}
