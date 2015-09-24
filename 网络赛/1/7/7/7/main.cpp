//
//  main.cpp
//  7
//
//  Created by wzcjj on 15/9/13.
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
#define maxn 1005
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int ans=0;
            for(j=x;j<=y;j++)if(ans<a[j])ans=a[j];
            printf("%d\n",ans);
        }
    }
    return 0;
}
