//
//  main.cpp
//  7
//
//  Created by wzcjj on 15/8/28.
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
#define maxn 10005
#define P 1000000007
#define INF 21000000000000LL
using namespace std;

struct node {
    long long y,z;
    friend bool operator<(node x,node y){
        if(x.y==y.y)return x.z<y.z;
        else return x.y<y.y;
    }
};
vector<node> a[maxn];
set<node>b[maxn];
queue<int>q;
bool flag[maxn];
int main(int argc, const char * argv[]) {
    int i,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<=n;i++)b[i].clear();
        memset(flag, 0, sizeof(flag));
        for(i=1;i<=m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            node t;
            t.y=y;
            t.z=z;
            a[x].push_back(t);
            t.y=x;
            a[y].push_back(t);
        }
        node t;
        t.y=0;
        t.z=-1;
        b[1].insert(t);
        q.push(1);
        flag[1]=true;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            flag[x]=false;
            node fl;
            fl.y=-1;
            fl.z=INF;
            for(set<node>::iterator it=b[x].begin();it!=b[x].end();it++)if((*it).y>fl.y&&(*it).z<fl.z){
                fl=(*it);
                for(i=0;i<a[x].size();i++)if(a[x][i].z>(*it).z){
                    t.y=(*it).y+a[x][i].z;
                    t.z=a[x][i].z;
                    if(b[a[x][i].y].size()){
                        set<node>::iterator it1=b[a[x][i].y].upper_bound(t);
                        if(it1!=b[a[x][i].y].begin()){
                            it1--;
                            if((*it1).z<=t.z)continue;
                        }
                    }
                    b[a[x][i].y].insert(t);
                    if(!flag[a[x][i].y]){
                        q.push(a[x][i].y);
                        flag[a[x][i].y]=true;
                    }
                }
            }
        }
        if(b[n].size()) {
            printf("%lld\n",(*b[n].begin()).y);
        }
        else{
            printf("No answer\n");
        }
    }
    return 0;
}
