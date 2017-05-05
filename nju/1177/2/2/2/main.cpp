//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/3/18.
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

int a[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,o,k,I=0;
    while (true) {
        scanf("%d%d%d",&n,&m,&o);
        if(n==0&&m==0&&o==0)break;
        printf("Case #%d\n",++I);
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)a[i][j]=INF;
        for(i=1;i<=n;i++)a[i][i]=0;
        for(i=1;i<=m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(a[x][y]>z){
                a[x][y]=a[y][x]=z;
            }
        }
        for(k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(max(a[i][k],a[k][j])<a[i][j])a[i][j]=max(a[i][k],a[k][j]);
                }
            }
        }
        for(i=1;i<=o;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",(a[x][y]==INF?1:a[x][y]));
        }
        printf("\n");
    }
    return 0;
}
