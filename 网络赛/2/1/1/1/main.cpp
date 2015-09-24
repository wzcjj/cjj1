//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/9/19.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
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
#define maxn 5000005
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        int x,y;
        int maxa1=0,mina1=INF,maxab1=0,minab1=INF;
        int maxa2=0,mina2=INF,maxab2=0,minab2=INF;
        scanf("%d%d%d",&n,&x,&y);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++){
            if(a[i]>maxa1){
                maxa2=maxa1;
                maxa1=a[i];
            }
            else if(a[i]>maxa2)
        }
    }
    return 0;
}
