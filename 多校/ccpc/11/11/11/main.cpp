//
//  main.cpp
//  11
//
//  Created by wzcjj on 16/8/14.
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

char s[maxn];
int a[30];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I=0;
    cin>>N;
    while (N--) {
        I++;
        scanf("%s",s);
        memset(a, 0, sizeof(a));
        n=strlen(s);
        for(i=0;i<n;i++){
            a[s[i]-'a']=1;
        }
        int cnt=0;
        for(i=0;i<26;i++){
            if(a[i])cnt++;
        }
        printf("Case #%d: %d\n",I,cnt);
    }
    return 0;
}
