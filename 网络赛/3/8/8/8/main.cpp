//
//  main.cpp
//  8
//
//  Created by wzcjj on 15/9/20.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include<iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn=1000;

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        double cc;
        scanf("%lf",&cc);
        long long b=(long long)((0.5-cc)*1000000000.0);
        int ans=-4;
        //printf("%ld\n",b);
        for (int i=1;i<=1000;i++)
        {
            b*=2;
            ans+=4;
            if (b>=1000000000LL) break;
        }
        //printf("%I64d\n",b);
        if (b==1000000000LL) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}