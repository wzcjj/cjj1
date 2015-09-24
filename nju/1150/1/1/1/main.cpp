//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/9/16.
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
#define maxn 1000005
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn];
int b[maxn];
int col[maxn];
queue<int> q;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    scanf("%d",&n);
    memset(b, 0, sizeof(b));
    memset(col, 0, sizeof(col));
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    for(i=1;i<=n;i++)if(b[i]==0)q.push(i);
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        col[x]=1;
        if(col[a[x]]==0){
            col[a[x]]=2;
            b[a[a[x]]]--;
            if(b[a[a[x]]]==0&&col[a[a[x]]]==0){
                q.push(a[a[x]]);
            }
        }
    }
    for(i=1;i<=n;i++)if(col[i]==0){
        q.push(i);
        while(!q.empty()) {
            int x=q.front();
            q.pop();
            col[x]=1;
            if(col[a[x]]==0){
                col[a[x]]=2;
                b[a[a[x]]]--;
                if(b[a[a[x]]]==0&&col[a[a[x]]]==0){
                    q.push(a[a[x]]);
                }
            }
        }
    }
    int ans=0;
    for(i=1;i<=n;i++)if(col[i]==2)ans++;
    printf("%d\n",ans);
    return 0;
}
