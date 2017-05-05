//
//  main.cpp
//  1
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
#define maxn 10005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
char s[105];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%s",s)!=EOF) {
        n=strlen(s);
        if(n>18){
            printf("TAT\n");
        }
        else {
            long long x=0;
            for(i=0;i<n;i++){
                x=x*10+s[i]-'0';
            }
            if(x==1)printf("0\n");
            else{
                for(i=1;i<=5;i++){
                    x=sqrt(x);
                    if(x==1)break;
                }
                if(x==1)printf("%d\n",i);
                else printf("TAT\n");
            }
        }
    }
    return 0;
}
