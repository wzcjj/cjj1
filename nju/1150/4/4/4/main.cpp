//
//  main.cpp
//  4
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
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;

vector<int> a[maxn];
list<int> b;
bool flag[maxn];
int ans[maxn];
queue<int>c;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(i=1;i<=n;i++)b.push_back(i);
    memset(flag,0,sizeof(flag));
    memset(ans, 0, sizeof(ans));
    while(!b.empty()){
        N++;
        c.push(*b.begin());
        b.erase(b.begin());
        ans[N]++;
        while(!c.empty()){
            int x=c.front();
            c.pop();
            for(i=0;i<a[x].size();i++){
                flag[a[x][i]]=true;
            }
            list<int>::iterator it;
            for(it=b.begin();it!=b.end();it++){
                if(!flag[*it]){
                    c.push(*it);
                    it=b.erase(it);
                    it--;
                    ans[N]++;
                }
            }
            for(i=0;i<a[x].size();i++){
                flag[a[x][i]]=false;
            }
        }
    }
    sort(ans+1,ans+1+N);
    printf("%d\n",N);
    for(i=1;i<=N;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
