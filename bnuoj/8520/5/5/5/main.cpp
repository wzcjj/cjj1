//
//  main.cpp
//  5
//
//  Created by wzcjj on 16/10/2.
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
#define maxn 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    long long a,b,c,ans=0;
    scanf("%lld%lld%lld",&a,&b,&c);
    if(a)ans=a+2*b;
    else ans=b;
    if((a&&b)||(a>1)){
        ans+=3*c;
    }
    else if(a){
        ans+=2*c;
    }
    else {
        if(b>2){
            if(c)ans+=(b-2)+3*c;
        }
        else ans+=(b+1)*c;
    }
    printf("%lld\n",ans);
    return 0;
}
