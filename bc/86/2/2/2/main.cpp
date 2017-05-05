//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/8/6.
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

int a[maxn];
bool b[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        memset(b, 0, sizeof(b));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        long long ans=0;
        a[n+1]=a[n-1];
        a[0]=a[2];
        long long maxx=0,maxi=1;
        for(i=1;i<n;i++){
            if(abs(a[i]-a[i+1])>maxx){
                maxx=abs(a[i]-a[i+1]);
                maxi=i;
            }
        }
        int cnt=0;
        for(i=1;i<=n-2;i++){
            if(abs(a[i]-a[i+2])>maxx){
                ans+=abs(a[i]-a[i+2]);
                b[i+1]=true;
                cnt++;
            }
        }
        ans+=maxx*(n-cnt-2+b[maxi]+b[maxi+1]);
        if(!b[maxi]){
            maxx=0;
            for(i=1;i<n;i++){
                if(abs(a[i]-a[i+1])>maxx&&i!=maxi-1&&i!=maxi){
                    maxx=abs(a[i]-a[i+1]);
                }
            }
            if(maxx<abs(a[maxi-1]-a[maxi+1]))maxx=abs(a[maxi-1]-a[maxi+1]);
            ans+=maxx;
        }
        if(!b[maxi+1]){
            maxx=0;
            for(i=1;i<n;i++){
                if(abs(a[i]-a[i+1])>maxx&&i!=maxi+1&&i!=maxi){
                    maxx=abs(a[i]-a[i+1]);
                }
            }
            if(maxx<abs(a[maxi]-a[maxi+2]))maxx=abs(a[maxi]-a[maxi+2]);
            ans+=maxx;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
