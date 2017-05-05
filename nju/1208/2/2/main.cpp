//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/7/3.
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
#define maxn 30005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,x,ti,y;
    n=30000;
    ti=600;
    for(i=1;i<=n;i++)a[i]=-ti-1;
    while (scanf("%d",&x)!=EOF) {
        char c;
        scanf(" %c",&c);
        if(c=='+'){
            for(i=1;i<=n;i++)if(x-a[i]>=ti){
                a[i]=x;
                printf("%d\n",i);
                break;
            }
        }
        else {
            scanf("%d",&y);
            if(x-a[y]<ti){
                printf("+\n");
                a[y]=x;
            }
            else printf("-\n");
        }
    }
    return 0;
}
