//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/5/4.
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
#define maxn 105
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

int a[maxn],b[maxn];
bool flag[maxn];
int ans,n;
void dfs(int deep,int now){
    if(deep>n){
        ans++;
        return;
    }
    if(b[deep]){
        for(int i=now+1;i<=n;i++){
            if(!flag[i]){
                flag[i]=true;
                dfs(deep+1,i);
                flag[i]=false;
            }
        }
    }
    else {
        for(int i=1;i<now;i++){
            if(!flag[i]){
                flag[i]=true;
                dfs(deep+1,i);
                flag[i]=false;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=2;i<=n;i++){
            b[i]=(a[i-1]<a[i]);
        }
        ans=0;
        b[1]=1;
        memset(flag,0,sizeof(flag));
        dfs(1,0);
        printf("%d\n",ans-1);
    }
    return 0;
}
