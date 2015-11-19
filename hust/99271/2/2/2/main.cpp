//
//  main.cpp
//  2
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
#define maxn 1000005
#define P 1000000007
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;

char ans[maxn];
stack<int> sta;
char getch(char c){
    if(c=='\n'||c=='\t')return ' ';
    else return c;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    int I=0;
    char c;
    while (N--) {
        I++;
        printf("Case #%d:\n",I);
        int now=0;
        while(true){
            scanf("%c",&c);
            if(c=='<'){
                ans[now++]=c;
                while(true){
                    scanf("%c",&c);
                    if(c=='"'){
                        ans[now++]=c;
                        while(true){
                            scanf("%c",&c);
                            if(c=='"'){
                                ans[now++]=c;
                                break;
                            }
                            else {
                                ans[now++]=getch(c);
                            }
                        }
                    }
                    else {
                        if(c=='/'){
                            
                        }
                    }
                }
            }
        }
    }
    return 0;
}
