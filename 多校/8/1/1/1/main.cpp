//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/8/11.
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
#define maxn 1005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn],l[maxn],r[maxn],b[maxn],c[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        memset(c, 0, sizeof(c));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d%d",&l[i],&r[i]);
        }
        bool flag=0;
        for(i=1;i<=n;i++){
            while(a[i]!=b[++c[a[i]]]&&c[a[i]]<=n);
            if(c[i]>n){
                flag=1;
                break;
            }
            int s=i,t=c[a[i]];
            for(j=1;j<=m;j++){
                if(l[j]<=s&&r[j]>=s){
                    if(l[j]<=t&&r[j]>=t){
                        s=t;
                        break;
                    }
                    else if(l[j]>t)s=l[j];
                    else s=r[j];
                }
            }
            if(s!=t){
                flag=1;
                break;
            }
        }
        if(flag)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
