//
//  main.cpp
//  2
//
//  Created by wzcjj on 15/8/4.
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
#define maxn 500005
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,z,l,sum;
    cin>>N;
    while (N--) {
        scanf("%d%d%d%d",&n,&m,&z,&l);
        a[1]=0;
        for(i=2;i<=n;i++)a[i]=(a[i-1]*m+z)%l;
        sum=0;
        //for(i=1;i<=n;i++)cout<<a[i]<<' ';
        //cout<<endl;
        for(i=1;i<=n;i++)
            sum^=((a[i])*2);
        cout<<sum<<endl;
    }
    return 0;
}
