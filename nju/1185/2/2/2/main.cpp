//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/4/22.
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
#define maxn 105
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

int fa[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,x,y;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        memset(fa,-1,sizeof(fa));
        for(i=1;i<=n;i++){
            scanf("%d%d",&x,&m);
            for(j=1;j<=m;j++){
                scanf("%d",&y);
                fa[y]=x;
            }
        }
        scanf("%d%d",&x,&y);
        while(x!=-1){
            int z=y;
            while(z!=-1){
                if(x==z)break;
                z=fa[z];
            }
            if(x==z)break;
            x=fa[x];
        }
        printf("%d\n",x);
    }
    return 0;
}
