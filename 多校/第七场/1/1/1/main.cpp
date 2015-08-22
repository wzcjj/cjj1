//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/8/11.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 10005
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn];
string ito(int x) {
    int now = 0,tmp = x;
    string str;
    while(x) {
        str+= (x % 10)+'0';
        x /= 10;
    }
    string st;
    for(int i=str.size()-1;i>=0;i--){
        st+=str[i];
    }
    return st;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    scanf("%d%d",&n,&m);
    int I=0;
    while (n!=-1||m!=-1) {
        I++;
        int t=n,sum=0;
        while(t){
            sum+=t%10;
            t/=10;
        }
        for(i=1;i<=m;i++){
            n%=11;
            int t=sum,tt=1,ttt=0;
            while(t){
                ttt+=t%10;
                t/=10;
                tt*=10;
            }
            n=n*tt+sum;
            sum+=ttt;
        }
        n%=11;
        if(n==0)printf("Case #%d: Yes\n",I);
        else printf("Case #%d: No\n",I);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
