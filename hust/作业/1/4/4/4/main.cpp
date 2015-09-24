//
//  main.cpp
//  4
//
//  Created by wzcjj on 15/8/23.
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
struct node
{
    double x,y;
};
const double eps=1e-5;
double p,q,r;
double dis(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double cal_ab(node a,node b,node m)
{
    node left=a,right=b;
    node midl,midr;
    double ans1,ans2;
    do
    {
        midr.x=(left.x+right.x)/2.0;
        midr.y=(left.y+right.y)/2.0;
        midl.x=(left.x+midr.x)/2.0;
        midl.y=(left.y+midr.y)/2.0;
        ans1=dis(midr,a)/p+dis(midr,m)/r;
        ans2=dis(midl,a)/p+dis(midl,m)/r;
        if(ans1<ans2)
            left=midl;
        else
            right=midr;
    }while(fabs(ans1-ans2)>eps);
    return ans1;
}
double cal_abcd(node a,node b,node c,node d)
{
    node left=c,right=d;
    node midl,midr;
    double ans1,ans2;
    do
    {
        midr.x=(left.x+right.x)/2.0;
        midr.y=(left.y+right.y)/2.0;
        midl.x=(left.x+midr.x)/2.0;
        midl.y=(left.y+midr.y)/2.0;
        ans1=dis(midr,d)/q+cal_ab(a,b,midr);
        ans2=dis(midl,d)/q+cal_ab(a,b,midl);
        if(ans1<ans2)
            left=midl;
        else
            right=midr;
    }while(fabs(ans1-ans2)>eps);
    return ans1;
}
int main()
{
    int t;
    node a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
        scanf("%lf%lf%lf",&p,&q,&r);
        printf("%.2lf\n",cal_abcd(a,b,c,d));
    }
    return 0;
}