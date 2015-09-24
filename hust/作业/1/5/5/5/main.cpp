//
//  main.cpp
//  5
//
//  Created by wzcjj on 15/8/22.
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
#define maxn 10005
#define P 1000000007
#define INF 2100000000
using namespace std;

int n;
struct node{
    double x,y;
    friend double dis(node b,node a){
        return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
    }
}p[maxn];

double sum(double x,double y){
    node a;
    a.x = x;
    a.y = y;
    double d=0;
    for(int i=1;i<=n;i++){
        d+=dis(a,p[i]);
    }
    return d;
}

double cal(double x){
    double l = 0;
    double r = 10000;
    for(int i=1;i<=200;i++){
        double midl = (l+r)/2;
        double midr = (midl+r)/2;
        if(sum(x,midl)<sum(x,midr))r = midr;
        else l = midl;
    }
    return sum(x,l);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    double l = 0;
    double r = 10000;
    for(int i=1;i<=200;i++){
        double midl = (l+r)/2;
        double midr = (midl+r)/2;
        if(cal(midl)<cal(midr))r = midr;
        else l = midl;
    }
    printf("%.0f\n",cal(l));
    return 0;
}