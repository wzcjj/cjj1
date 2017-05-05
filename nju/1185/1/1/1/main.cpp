//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/4/22.
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
#define maxn 15
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

int a[maxn];
bool flag[maxn];
int n;
double ans;
void dfs(int x,int cnt){
    if(x>n){
        if(cnt&1){
            double t=365;
            for(int i=1;i<=n;i++)if(flag[i]){
                t/=a[i];
            }
            ans-=t;
        }
        else {
            double t=365;
            for(int i=1;i<=n;i++)if(flag[i]){
                t/=a[i];
            }
            ans+=t;
        }
    }
    else {
        for(int i=0;i<2;i++){
            flag[x]=i;
            dfs(x+1,cnt+i);
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
        ans=0;
        dfs(1,0);
        cout<<ans<<' '<<(ans*(1-ans/365)+(365-ans)*(ans/365))/2<<endl;
        //printf("%lf %lf\n",ans,(ans*(1-ans/365)+(365-ans)*(ans/365))/2);
    }
    return 0;
}
