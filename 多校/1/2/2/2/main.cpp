//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/7/19.
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

int a[1<<21];
int b[25];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    memset(a,0,sizeof(a));
    for(i=1;i<(1<<20);i++){
        memset(b,0,sizeof(b));
        for(j=0;j<20;j++){
            if(i&(1<<j)){
                for(int k=j-1;k>=0;k--){
                    if(!(i&(1<<k))){
                        int x=i^(1<<j)^(1<<k);
                        b[a[x]]=1;
                        break;
                    }
                }
            }
        }
        for(j=0;b[j];j++);
        a[i]=j;
    }
    /*for(i=1;i<(1<<20);i++){
        int x=0;
        for(j=0;j<20;j++)if(i&(1<<j)){
            x^=(1<<(19-j));
        }
        if(a[i]!=a[x]){
            printf("%d\n",i);
            break;
        }
    }*/
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        int ans=0;
        for(i=1;i<=n;i++){
            scanf("%d",&m);
            int now=0;
            for(j=1;j<=m;j++){
                int x;
                scanf("%d",&x);
                now^=(1<<(20-x));
            }
            ans^=a[now];
        }
        if(ans){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
