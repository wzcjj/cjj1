//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/4/8.
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
#define maxn 205
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

vector<int> a[maxn];
int b[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        int cnt=0;
        for(i=0;i<3*n;i++)a[i].clear();
        for(i=0;i<3*n;i++){
            scanf("%d",&b[i]);
        }
        for(i=0;i<3*n;i++){
            for(j=i+1;j<3*n;j++){
                if(i/3!=j/3&&b[i]+b[j]){
                    a[i].push_back(j);
                    a[j].push_back(i);
                }
            }
        }
        printf("%d %d\n",3*n,n);
        for(i=0;i<3*n;i++){
            printf("%d",i);
            for(j=0;j<a[i].size();j++) {
                printf(" %d",a[i][j]);
            }
            printf("\n");
        }
        if(N)printf("\n");
    }
    return 0;
}
