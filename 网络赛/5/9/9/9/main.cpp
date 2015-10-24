//
//  main.cpp
//  9
//
//  Created by wzcjj on 15/9/27.
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
#define maxn 35
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn][maxn];
struct node{
    int a,b;
    friend bool operator<(node x,node y){
        if(x.a==y.a)return x.b<y.b;
        else return x.a<y.a;
    }
};
set<node> dp[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    int I=0;
    while (N--) {
        scanf("%d%d",&m,&n);
        I++;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                dp[i][j].clear();
            }
        }
        node t;
        t.a=a[1][1];
        t.b=a[1][1];
        dp[1][1].insert(t);
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(i>1){
                    for(set<node>::iterator k=dp[i-1][j].begin();k!=dp[i-1][j].end();k++){
                        t.a=(*k).a+a[i][j];
                        t.b=(*k).b+a[i][j]*a[i][j];
                        dp[i][j].insert(t);
                    }
                }
                if(j>1){
                    for(set<node>::iterator k=dp[i][j-1].begin();k!=dp[i][j-1].end();k++){
                        t.a=(*k).a+a[i][j];
                        t.b=(*k).b+a[i][j]*a[i][j];
                        dp[i][j].insert(t);
                    }
                }
                /*if(i==1&&j==1)continue;
                if(j==1){
                    dp[i][j].a=dp[i-1][j].a+a[i][j];
                    dp[i][j].b=dp[i-1][j].b+a[i][j]*a[i][j];
                }
                else if(i==1){
                    dp[i][j].a=dp[i][j-1].a+a[i][j];
                    dp[i][j].b=dp[i][j-1].b+a[i][j]*a[i][j];
                }
                else{
                    int x,y;
                    x=(i+j-1)*(dp[i-1][j].b+a[i][j]*a[i][j])-(dp[i-1][j].a+a[i][j])*(dp[i-1][j].a+a[i][j]);
                    y=(i+j-1)*(dp[i][j-1].b+a[i][j]*a[i][j])-(dp[i][j-1].a+a[i][j])*(dp[i][j-1].a+a[i][j]);
                    if(x<y){
                        dp[i][j].a=dp[i-1][j].a+a[i][j];
                        dp[i][j].b=dp[i-1][j].b+a[i][j]*a[i][j];
                    }
                    else{
                        dp[i][j].a=dp[i][j-1].a+a[i][j];
                        dp[i][j].b=dp[i][j-1].b+a[i][j]*a[i][j];
                    }
                }*/
            }
        }
        int mi=INF;
        for(set<node>::iterator k=dp[m][n].begin();k!=dp[m][n].end();k++){
            if(mi>(n+m-1)*((*k).b)-(*k).a*(*k).a)mi=(n+m-1)*((*k).b)-(*k).a*(*k).a;
        }
        printf("Case #%d: %d\n",I,mi);
    }
    return 0;
}
