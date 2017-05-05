//
//  main.cpp
//  5698
//
//  Created by wzcjj on 16/4/23.
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
#define maxn 15
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

int a[maxn][maxn];
int p[maxn],b[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        for(i=1;i<=5;i++){
            scanf("%d",&n);
            for(j=1;j<=4;j++)scanf("%d",&a[i][j]);
            if(i==1){
                if(n==1){
                    p[i]=2;
                    b[i]=a[i][2];
                }
                else {
                    p[i]=n;
                    b[i]=a[i][n];
                }
            }
            else if(i==2){
                if(n==1){
                    for(j=1;j<=4;j++)if(a[i][j]==4){
                        p[i]=j;
                        break;
                    }
                    b[i]=4;
                }
                else if(n==2||n==4){
                    p[i]=p[i-1];
                    b[i]=a[i][p[i]];
                }
                else {
                    p[i]=1;
                    b[i]=a[i][1];
                }
            }
            else if(i==3){
                if(n==1||n==2){
                    b[i]=b[3-n];
                    for(j=1;j<=4;j++)if(a[i][j]==b[i]){
                        p[i]=j;
                        break;
                    }
                }
                else if(n==3){
                    p[i]=3;
                    b[i]=a[i][3];
                }
                else {
                    for(j=1;j<=4;j++)if(a[i][j]==4){
                        p[i]=j;
                        break;
                    }
                    b[i]=4;
                }
            }
            else if(i==4){
                if(n==1){
                    p[i]=p[1];
                    b[i]=a[i][p[i]];
                }
                else if(n==2){
                    p[i]=1;
                    b[i]=a[i][1];
                }
                else {
                    p[i]=p[2];
                    b[i]=a[i][p[i]];
                }
            }
            else {
                if(n==1||n==2){
                    b[i]=b[n];
                    for(j=1;j<=4;j++)if(a[i][j]==b[i]){
                        p[i]=j;
                        break;
                    }
                }
                else {
                    b[i]=b[7-n];
                    for(j=1;j<=4;j++)if(a[i][j]==b[i]){
                        p[i]=j;
                        break;
                    }
                }
            }
            printf("%d %d\n",p[i],b[i]);
        }
    }
    return 0;
}
