//
//  main.cpp
//  2
//
//  Created by wzcjj on 15/9/10.
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
vector<int>b[maxn];
bool flag[maxn];
void dfs(int x){
    flag[x]=true;
    for(int i=0;i<b[x].size();i++){
        if(!flag[b[x][i]])dfs(b[x][i]);
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    scanf("%d",&n);
    memset(flag,0,sizeof(flag));
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[a[i]].push_back(i);
    }
    int ans=0;
    for(i=1;i<=n;i++){
        if(!flag[i]){
            ans++;
            j=i;
            while(!flag[j]){
                dfs(j);
                j=a[j];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
