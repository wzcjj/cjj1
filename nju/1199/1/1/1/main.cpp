//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/6/3.
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

struct node{
    int x,y;
};
node a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        int ans=INF,x=1,y=1;
        for(i=1;i<=100;i++){
            for(j=1;j<=100;j++){
                int cnt=0;
                for(int k=1;k<=n;k++){
                    cnt+=abs(a[k].x-i)+abs(a[k].y-j);
                }
                if(cnt<ans||(cnt==ans&&i+j<x+y)){
                    ans=cnt;
                    x=i;
                    y=j;
                }
            }
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
