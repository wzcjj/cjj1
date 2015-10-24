//
//  main.cpp
//  5
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
#define maxn 130
#define P 1000000007
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define d(p,q) sqrt((a[p].x-a[q].x)*(a[p].x-a[q].x)+(a[p].y-a[q].y)*(a[p].y-a[q].y))
using namespace std;
struct node{
    int x,y;
};
node a[maxn];
bool ans[maxn];
int n,m;
bool flag[maxn];
bool check(){
    queue<int> q;
    while(!q.empty())q.pop();
    q.push(1);
    memset(flag,0,sizeof(flag));
    flag[1]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=1;i<=n;i++)if(!flag[i]){
            if(ans[i]){
                if((int)ceil(d(x,i))<=m){
                    flag[i]=true;
                    q.push(i);
                }
            }
            else {
                if((int)ceil(d(x,i))*2<=m){
                    flag[i]=true;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)if(!flag[i])return false;
    return true;
}
int main(int argc, const char * argv[]) {
    int i,j,N;
    while (scanf("%d%d",&n,&m)!=EOF) {
        memset(ans, 0, sizeof(ans));
        for(i=1;i<=n;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        for(i=1;i<=n;i++){
            ans[i]=1;
            if(check())break;
        }
        if(i==n+1){
            printf("-1\n");
            continue;
        }
        int cnt=i;
        for(i=cnt;i>=1;i--){
            ans[i]=0;
            if(!check())ans[i]=1;
        }
        ans[1]=1;
        while(cnt>1&&ans[cnt]==0)cnt--;
        for(i=cnt;i>=1;i--){
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
