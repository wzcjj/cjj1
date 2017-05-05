//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/4/15.
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

int a[maxn][2];
bool flag[maxn];
int ans[2][maxn];
bool fl;
int head;
int n;
void dfs(int x,int ne,int deep){
    ans[0][deep]=x;
    flag[x]=true;
    if(deep==n){
        if(ne==head)fl=true;
        return;
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==false){
            if(a[i][0]==ne)dfs(i,a[i][1],deep+1);
            if(fl)return;
            if(a[i][1]==ne)dfs(i,a[i][0],deep+1);
            if(fl)return;
        }
    }
    flag[x]=false;
}
int main(int argc, const char * argv[]) {
    int i,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d%d",&a[i][0],&a[i][1]);
        }
        int t=0;
        for(i=1;i<=n;i++){
            t=t^a[i][0]^a[i][1];
        }
        if(t){
            printf("-1\n");
            continue;
        }
        memset(flag,0,sizeof(flag));
        fl=false;
        head=a[1][1];
        dfs(1,a[1][0],1);
        if(!fl){
            printf("-1\n");
            continue;
        }
        memset(flag,0,sizeof(flag));
        for(i=1;i<=n;i++)ans[1][i]=ans[0][i];
        fl=false;
        head=a[1][0];
        dfs(1,a[1][1],1);
        int z=0;
        for(i=1;i<=n;i++){
            if(ans[0][i]<ans[1][i]){
                z=0;
                break;
            }
            else if(ans[0][i]>ans[1][i]){
                z=1;
                break;
            }
        }
        for(i=1;i<=n;i++){
            printf("%d ",ans[z][i]);
        }
        printf("1\n");
    }
    return 0;
}
