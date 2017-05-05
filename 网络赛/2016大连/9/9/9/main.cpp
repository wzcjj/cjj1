//
//  main.cpp
//  9
//
//  Created by wzcjj on 16/9/10.
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
#define maxn 200005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

vector<int> a[maxn];
queue<int> q;
bool flag[maxn];
int d[maxn];
int b[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for(i=1;i<=n;i++)d[i]=-1;
        int s;
        scanf("%d",&s);
        d[s]=0;
        int cnt=0,now=0;
        while(true){
            cnt=0;
            memset(b, 0, sizeof(b));
            for(i=1;i<=n;i++)if(d[i]==now){
                cnt++;
                for(j=0;j<a[i].size();j++){
                    if(d[a[i][j]]==-1){
                        b[a[i][j]]++;
                    }
                }
            }
            if(cnt==0)break;
            for(i=1;i<=n;i++)if(d[i]==-1&&b[i]!=cnt)d[i]=now+1;
            now++;
        }
        cnt=0;
        for(i=1;i<=n;i++)if(i!=s){
            cnt++;
            printf("%d",d[i]);
            if(cnt==n-1)printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
