//
//  main.cpp
//  10
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
#define maxn 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
int b[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I=0;
    cin>>N;
    while (N--) {
        I++;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(b,127,sizeof(b));
        b[0]=-1;
        int cnt=0;
        for(i=1;i<=n;i++){
            if(a[i]){
                int l=cnt,r=i;
                while(l<r-1){
                    int mid=(l+r)>>1;
                    if(b[mid-cnt]+cnt<a[i])l=mid;
                    else r=mid;
                }
                b[r-cnt]=a[i]-cnt;
            }
            else {
                cnt++;
            }
        }
        while(b[i]==b[i+1])i--;
        printf("Case #%d: %d\n",I,i+cnt);
    }
    return 0;
}
