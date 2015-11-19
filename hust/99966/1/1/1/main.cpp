//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/11/18.
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
#define maxn 10005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

int a[maxn];
char s[100000];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (scanf("%s",s)!=EOF) {
        n=strlen(s);
        for(i=0;i<n;i++){
            if(strncmp(s+i,"Apple",5)==0||strncmp(s+i,"iPhone",6)==0||strncmp(s+i,"iPod",4)==0||strncmp(s+i,"iPad",4)==0){puts("MAI MAI MAI!");/*printf("%d\n",i);*/}
            if(strncmp(s+i,"Sony",4)==0)puts("SONY DAFA IS GOOD!");
        }
    }
    return 0;
}
