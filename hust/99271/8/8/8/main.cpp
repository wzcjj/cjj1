//
//  main.cpp
//  8
//
//  Created by wzcjj on 15/11/11.
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
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;

int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    int I=0;
    while (N--) {
        scanf("%d",&n);
        I++;
        printf("Case #%d: ",I);
        char s[20];
        scanf("%s",s);
        if(s[1]=='B'){
            printf("0.00%%\n");
        }
        else if(s[1]=='K'){
            printf("2.34%%\n");
        }
        else if(s[1]=='M'){
            printf("4.63%%\n");
        }
        else if(s[1]=='G'){
            printf("6.87%%\n");
        }
        else if(s[1]=='T'){
            printf("9.05%%\n");
        }
        else if(s[1]=='P'){
            printf("11.18%%\n");
        }
        else if(s[1]=='E'){
            printf("13.26%%\n");
        }
        else if(s[1]=='Z'){
            printf("15.30%%\n");
        }
        else if(s[1]=='Y'){
            printf("17.28%%\n");
        }
    }
    return 0;
}
