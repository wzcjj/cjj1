//
//  main.cpp
//  1
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
#define maxn 10005
#define P 1000000007
#define INF 2100000000
using namespace std;

int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    scanf("%d",&n);
        int maxx=-INF;
        int si=0;
        for(i=1;i<=n;i++){
            scanf("%d",&m);
            if(m==1){
                scanf("%d",&m);
                si++;
                if(m>maxx)maxx=m;
            }
            else if(m==2){
                if(si>0)si--;
                if(si==0)maxx=-INF;
            }
            else{
                if(si>0)printf("%d\n",maxx);
                else printf("0\n");
            }
        }
    return 0;
}
