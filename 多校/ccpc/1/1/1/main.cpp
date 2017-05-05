//
//  main.cpp
//  1
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
#define maxn 10000005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

char s[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,I=0;
    while (scanf("%s",s)!=EOF) {
        I++;
        n=strlen(s);
        /*for(i=0;i<n-4;i++){
            if(i>0&&s[i-1]>'0'){
                s[i-1]--;
                s[i]+=10;
            }
            while(s[i]>'0'){
                s[i]--;
                if(s[i+4]!='0'){
                    s[i+4]--;
                }
                else if(s[i+3]!='0'){
                    s[i+3]--;
                    s[i+4]='9';
                }
                else if(s[i+2]!='0'){
                    s[i+2]--;
                    s[i+3]=s[i+4]='9';
                }
                else if(s[i+1]!='0'){
                    s[i+1]--;
                    s[i+2]=s[i+3]=s[i+4]='9';
                }
                else if(s[i]>'0'){
                    s[i]--;
                    s[i+1]=s[i+2]=s[i+3]=s[i+4]='9';
                }
            }
        }*/
        int ans=0;
        for(i=0;i<n;i++){
            ans*=10;
            ans+=s[i]-'0';
            if(ans>10000)ans%=10001;
        }
        if(ans==0)printf("Case #%d: YES\n",I);
        else printf("Case #%d: NO\n",I);
    }
    return 0;
}
