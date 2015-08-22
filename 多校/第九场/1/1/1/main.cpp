//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/8/18.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MOD 1000000007
#define MAX 105
#define NIL

typedef long long LL;
typedef vector<int> VI;
typedef priority_queue<int> PQI;
LL fib[MAX];
int n;
LL num[MAX];
int op[MAX];
LL work(int b,int e) {
    if(b == e) return num[b];
    LL ans = 0;
    for(int i = b;i < e;i++) {
        LL ans1 = work(b,i);
        LL ans2 = work(i+1,e);
        LL k1 = fib[i-b];
        LL k2 = fib[e-i-1];
        LL ret;
        if(op[i] == 1) {
            ret = ans1 * k2 + ans2 * k1;
        }
        else if(op[i] == 2) {
            ret = ans1 * k2 - ans2 * k1;
        }
        else if(op[i] == 3) {
            ret = ans1 * ans2 ;
        }
        printf("%d %d %lld %lld %lld %lld %lld\n",b,e,k1,k2,ans1,ans2,ret);
        ans += ret;
        ans %= MOD;
        ans += MOD;
        ans %= MOD;
    }
    
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    memset(fib,0,sizeof fib);
    fib[0] = 1;fib[1] = 1;
    for(int i = 2;i <= 100;i++) {
        fib[i] = fib[i-1] * i;
        fib[i] %= MOD;
        fib[i] += MOD;
        fib[i] %= MOD;
    }
    while(scanf("%d",&n) != EOF) {
        for(int i = 1;i <= n;i++) scanf("%d",&num[i]);
        char str[MAX],c;
        scanf("%s",str);
        //printf("%s\n",str);
        for(int i = 0;i < n-1;i++) {
            c = str[i];
            if(c == '+') op[i+1] = 1;
            else if(c == '-') op[i+1] = 2;
            else if(c == '*') op[i+1] = 3;
        }
        printf("%lld\n",work(1,n));
    }
    return 0;
}