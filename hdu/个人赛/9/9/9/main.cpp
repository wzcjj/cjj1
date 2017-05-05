//
//  main.cpp
//  9
//
//  Created by wzcjj on 15/12/26.
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
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    char c;
    while (scanf("%c",&c)!=EOF) {
        int wh,wa,wd,bh,ba,bd;
        scanf("%d%d%d%d%d%d\n",&wh,&wa,&wd,&bh,&ba,&bd);
        if(wa<=bd){
            printf("Warrior loses\n");
            continue;
        }
        if(c=='B'){
            wh-=max(ba-wd,0);
            if(wh<=0){
                printf("Warrior loses\n");
                continue;
            }
        }
        while(true){
            bh-=max(wa-bd,0);
            if(bh<=0){
                printf("Warrior wins\n");
                break;
            }
            wh-=max(ba-wd,0);
            if(wh<=0){
                printf("Warrior loses\n");
                break;
            }
        }
    }
    return 0;
}
