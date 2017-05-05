//
//  main.cpp
//  11
//
//  Created by wzcjj on 16/7/26.
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

struct node{
    int x,y;
};
node a[maxn];
bool b[maxn<<1];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for(i=1;i<=n;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        if(n>500){
            printf("YES\n");
        }
        else {
            bool z=0;
            for(i=1;i<=n;i++){
                for(j=i+1;j<=n;j++){
                    if(b[abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)]){
                        z=1;
                        break;
                    }
                    else {
                        b[abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)]=1;
                    }
                }
                if(z)break;
            }
            if(z)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
