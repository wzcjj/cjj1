//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/3/3.
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
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

struct edge{
    int y,z;
};
vector<edge> a[maxn];
queue<int> b;
bool flag[maxn];
int ans[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,o;
    cin>>N;
    while (N--) {
        int x1,y1,z1;
        scanf("%d%d%d",&n,&m,&o);
        for(i=0;i<n;i++)a[i].clear();
        memset(flag,false,sizeof(flag));
        for(i=0;i<n;i++)ans[i]=INF;
        for(i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(i==o){
                x1=x;
                y1=y;
                z1=z;
            }
            else {
                edge t;
                t.y=y;
                t.z=z;
                a[x].push_back(t);
                t.y=x;
                a[y].push_back(t);
            }
        }
        ans[x1]=0;
        flag[x1]=true;
        b.push(x1);
        while(!b.empty()){
            int x=b.front();
            b.pop();
            flag[x]=false;
            for(i=0;i<a[x].size();i++){
                if(a[x][i].z+ans[x]<ans[a[x][i].y]){
                    ans[a[x][i].y]=a[x][i].z+ans[x];
                    if(!flag[a[x][i].y]){
                        flag[a[x][i].y]=true;
                        b.push(a[x][i].y);
                    }
                }
            }
        }
        if(ans[y1]==INF)printf("No Cycle!\n");
        else printf("%d\n",ans[y1]+z1);
    }
    return 0;
}
