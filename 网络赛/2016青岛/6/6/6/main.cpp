//
//  main.cpp
//  6
//
//  Created by wzcjj on 16/9/17.
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
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(b, 0, sizeof(b));
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            b[x]++;
            b[y]++;
        }
        int cnt=0,sum=0;
        for(i=1;i<=n;i++){
            if((b[i]&3)==3){
                cnt++;
            }
            else if(b[i]&2){
                sum^=a[i];
            }
            else if(b[i]&1){
                sum^=a[i];
                cnt++;
            }
        }
        int maxx=0;
        if(cnt>2){
            printf("Impossible\n");
            continue;
        }
        else if(cnt==0){
            for(i=1;i<=n;i++)if(b[i]){
                if(maxx<(sum^a[i])){
                    maxx=sum^a[i];
                }
            }
        }
        else {
            maxx=sum;
        }
        printf("%d\n",maxx);
    }
    return 0;
}
