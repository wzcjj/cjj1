//
//  main.cpp
//  4
//
//  Created by wzcjj on 16/8/16.
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
#define maxn 2010
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
bool b[3*maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n=20,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        memset(b, 0, sizeof(b));
        int now=20;
        for(i=1;i<=n;i++){
            while(b[now])now+=1;
            a[i]=now;
            int sum=0;
            for(j=i;j>=1;j--){
                sum+=a[j];
                if(sum<3*(n+6))b[sum]=1;
            }
        }
        
        for(i=1;i<n;i++)printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}
