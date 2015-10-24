//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/9/26.
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
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;

int c[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,a,b;
    cin>>N;
    int I=0;
    while (N--) {
        I++;
        memset(c, 0, sizeof(c));
        scanf("%d%d%d%d",&n,&a,&b,&m);
        for(i=1;i<=n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            c[x]+=a;
            c[y]-=a;
        }
        for(i=1;i<=m;i++){
            c[i]+=c[i-1];
        }
        int ans=0,mi=0;
        for(i=0;i<=m;i++){
            if(c[i])ans-=a;
            else ans+=b;
            if(ans<mi)mi=ans;
        }
        printf("Case #%d: %d\n",I,-mi);
    }
    return 0;
}
