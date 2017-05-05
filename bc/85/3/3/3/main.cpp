//
//  main.cpp
//  3
//
//  Created by wzcjj on 16/7/30.
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

int a[maxn];
int main(int argc, const char * argv[]) {
    long long i,j,m,n,N,x,y,ans;
    cin>>N;
    while (N--) {
        scanf("%lld",&x);
        y=sqrt(x);
        for(i=y;i>=0;i--){
            int z=0,t=i;
            for(j=2;j*j<=t;j++){
                if(t%j==0){
                    t/=j;
                    if(t%j==0){
                        z=1;
                        break;
                    }
                }
            }
            if(!z)break;
        }
        ans=x-i*i;
        for(i=y+1;;i++){
            int z=0,t=i;
            for(j=2;j*j<=t;j++){
                if(t%j==0){
                    t/=j;
                    if(t%j==0){
                        z=1;
                        break;
                    }
                }
            }
            if(!z)break;
        }
        ans=min(ans,i*i-x);
        printf("%lld\n",ans);
    }
    return 0;
}
