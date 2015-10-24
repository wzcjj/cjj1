//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/9/27.
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
using namespace std;

int howManyBits(long long x){
    int cnt=0;
    while(x){
        cnt++;
        x=x^(x&(-x));
    }
    return cnt;
}
int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,N,x,y;
    long long n;
    cin>>N;
    int I=0;
    while (N--) {
        I++;
        printf("Case #%d: ",I);
        scanf("%lld%d%d",&n,&x,&y);
        if(n==0){
            printf("1\n");
            continue;
        }
        if(howManyBits(n)==y){
            for(i=0;i<=63;i++)if(n&(1LL<<i)){
                break;
            }
            for(;i<=63;i++)if(!(n&(1LL<<i))){
                n=n^(1LL<<i);
                break;
            }
            j=i;
            for(i=i-1LL;i>=0;i--){
                //cout<<howManyBits(n)<<endl;
                if(n&(1LL<<i))n=n^(1LL<<i);
                //cout<<n<<endl;
            }
            for(i=0;i<=j;i++){
                if(howManyBits(n)<x){
                    n=n^(1LL<<i);
                }
            }
            printf("%lld\n",n);
        }
        else{
            n++;
            for(i=0;i<=63;i++){
                if(howManyBits(n)<x){
                    n=n^(1LL<<i);
                }
            }
            printf("%lld\n",n);
        }
    }
    return 0;
}
