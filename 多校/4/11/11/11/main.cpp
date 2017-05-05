//
//  main.cpp
//  11
//
//  Created by wzcjj on 16/7/28.
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

char s[100];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I=0;
    cin>>N;
    gets(s);
    while (N--) {
        I++;
        gets(s);
        if(strcmp(s,"Cleveland Cavaliers")==0)printf("Case #%d: 1\n",I);
        else if(strcmp(s,"Golden State Warriors")==0)printf("Case #%d: 2\n",I);
        else if(strcmp(s,"San Antonio Spurs")==0)printf("Case #%d: 5\n",I);
        else if(strcmp(s,"Miami Heat")==0)printf("Case #%d: 3\n",I);
        else if(strcmp(s,"Dallas Mavericks")==0)printf("Case #%d: 1\n",I);
        else if(strcmp(s,"L.A. Lakers")==0)printf("Case #%d: 11\n",I);
        else if(strcmp(s,"Boston Celtics")==0)printf("Case #%d: 17\n",I);
        else if(strcmp(s,"Detroit Pistons")==0)printf("Case #%d: 3\n",I);
        else if(strcmp(s,"Chicago Bulls")==0)printf("Case #%d: 6\n",I);
        else if(strcmp(s,"Houston Rockets")==0)printf("Case #%d: 2\n",I);
        else if(strcmp(s,"Philadelphia 76ers")==0)printf("Case #%d: 2\n",I);
        else if(strcmp(s,"Seattle Sonics")==0)printf("Case #%d: 1\n",I);
        else if(strcmp(s,"Washington Bullets")==0)printf("Case #%d: 1\n",I);
        else if(strcmp(s,"Portland Trail Blazers")==0)printf("Case #%d: 1\n",I);
        else if(strcmp(s,"New York Knicks")==0)printf("Case #%d: 2\n",I);
        else if(strcmp(s,"Milwaukee Bucks")==0)printf("Case #%d: 1\n",I);
        else if(strcmp(s,"St. Louis Hawks")==0)printf("Case #%d: 1\n",I);
        else if(strcmp(s,"Philadelphia Warriors")==0)printf("Case #%d: 2\n",I);
        else if(strcmp(s,"Syracuse Nats")==0)printf("Case #%d: 1\n",I);
        else if(strcmp(s,"Minneapolis Lakers")==0)printf("Case #%d: 5\n",I);
        else if(strcmp(s,"Rochester Royals")==0)printf("Case #%d: 1\n",I);
        else if(strcmp(s,"Baltimore Bullets")==0)printf("Case #%d: 1\n",I);
        else printf("Case #%d: 0\n",I);
    }
    return 0;
}
