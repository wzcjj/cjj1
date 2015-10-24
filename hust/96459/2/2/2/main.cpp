//
//  main.cpp
//  2
//
//  Created by wzcjj on 15/10/23.
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
    while (scanf("%d%d",&n,&m)!=EOF) {
        int ans=0;
        int nn=n;
        for(int s=1;s*s<=nn;s++)if(nn%s==0){
            n=s;
            while(n){
                int t = n%m;
                ans += t*t;
                n /= m;
            }
            if(s*s==nn)continue;
            n=nn/s;
            while(n){
                int t = n%m;
                ans += t*t;
                n /= m;
            }
        }
        a[0]=0;
        //cout<<ans<<endl;
        while(ans){
            a[0]++;
            a[a[0]]=ans%m;
            ans/=m;
        }
        for(i=a[0];i>=1;i--){
            if(a[i]<10)printf("%d",a[i]);
            else printf("%c",a[i]-10+'A');
        }
        printf("\n");
    }
    return 0;
}
