//
//  main.cpp
//  6
//
//  Created by wzcjj on 15/9/19.
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
using namespace std;

char s[maxn];
int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I=0;
    cin>>N;
    while (N--) {
        int ans=0;
        I++;
        scanf("%s",s);
        n = strlen(s);
        bool flag = false,flag1=false ,flag2=false;
        for(i=0;i<n;i++){
            if(s[i]=='c'){
                ans++;
                flag1=true;
                if(s[(i+1)%n]!='f'||s[(i+2)%n]!='f'){
                    flag=true;
                    break;
                }
                i+=2;
            }
            else if(s[i]=='f')flag2=true;
            else flag=true;
        }
        if(flag){
            printf("Case #%d: -1\n",I);
            continue;
        }
        if(flag1){
            printf("Case #%d: %d\n",I,ans);
        }
        else printf("Case #%d: %d\n",I,(n+1)/2);
    }
    return 0;
}
