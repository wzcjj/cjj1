//
//  main.cpp
//  10
//
//  Created by wzcjj on 16/8/9.
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
#define maxn 50005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
#define asd(x,y) ((!sign)?(x):(y))
using namespace std;

struct node{
    int t,v;
};
struct node1{
    int t,i;
    friend bool operator<(node1 x,node1 y){
        return x.t<y.t;
    }
};
stack<node> a[maxn];
priority_queue<node1> b,c;
char s[10];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N=0,I=0;
    while (true) {
        int sign=0;
        I++;
        scanf("%d",&n);
        if(n==0)break;
        printf("Case #%d:\n",I);
        int x=1,y=2;
        for(i=1;i<=N;i++)while(!a[i].empty())a[i].pop();
        N=2;
        while(!b.empty())b.pop();
        while(!c.empty())c.pop();
        for(i=1;i<=n;i++){
            scanf("%s",s);
            if(s[1]=='u'){
                scanf("%s",s);
                if(s[0]=='A'){
                    int v;
                    scanf("%d",&v);
                    node t;
                    t.t=i;
                    t.v=v;
                    a[x].push(t);
                }
                else {
                    int v;
                    scanf("%d",&v);
                    node t;
                    t.t=i;
                    t.v=v;
                    a[y].push(t);
                }
            }
            else if(s[1]=='o'){
                scanf("%s",s);
                if(s[0]=='A'){
                    node t;
                    t.t=-1;
                    if(!a[x].empty())t=a[x].top();
                    if(!asd(b,c).empty()){
                        node1 t1=asd(b,c).top();
                        if(t1.t>t.t){
                            node tt=a[t1.i].top();
                            a[t1.i].pop();
                            printf("%d\n",tt.v);
                            asd(b,c).pop();
                            if(!a[t1.i].empty()){
                                t1.t=a[t1.i].top().t;
                                asd(b,c).push(t1);
                            }
                        }
                        else {
                            printf("%d\n",t.v);
                            a[x].pop();
                        }
                    }
                    else {
                        printf("%d\n",t.v);
                        a[x].pop();
                    }
                }
                else {
                    node t;
                    t.t=-1;
                    if(!a[y].empty())t=a[y].top();
                    if(!asd(c,b).empty()){
                        node1 t1=asd(c,b).top();
                        if(t1.t>t.t){
                            node tt=a[t1.i].top();
                            a[t1.i].pop();
                            printf("%d\n",tt.v);
                            asd(c,b).pop();
                            if(!a[t1.i].empty()){
                                t1.t=a[t1.i].top().t;
                                asd(c,b).push(t1);
                            }
                        }
                        else {
                            printf("%d\n",t.v);
                            a[y].pop();
                        }
                    }
                    else {
                        printf("%d\n",t.v);
                        a[y].pop();
                    }
                }
            }
            else {
                scanf("%s%*s",s);
                if(s[0]=='A'){
                    if(asd(b,c).size()<asd(c,b).size())sign=!sign;
                    if(!a[y].empty()){
                        node1 t1;
                        t1.t=a[y].top().t;
                        t1.i=y;
                        asd(b,c).push(t1);
                        y=++N;
                    }
                    while(!asd(c,b).empty()){
                        asd(b,c).push(asd(c,b).top());
                        asd(c,b).pop();
                    }
                }
                else {
                    if(asd(b,c).size()>asd(c,b).size())sign=!sign;
                    if(!a[x].empty()){
                        node1 t1;
                        t1.t=a[x].top().t;
                        t1.i=x;
                        asd(c,b).push(t1);
                        x=++N;
                    }
                    while(!asd(b,c).empty()){
                        asd(c,b).push(asd(b,c).top());
                        asd(b,c).pop();
                    }
                }
            }
        }
    }
    return 0;
}
