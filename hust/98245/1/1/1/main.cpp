//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/11/4.
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
#define maxn 505
#define P 1000000007
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;

int a[maxn][maxn];
int b[maxn][maxn];
bool no[maxn][maxn],ne[maxn][maxn],flag[maxn][maxn];
int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct node{
    int x,y,t,now;
};
queue<node> q;
int n;
inline bool check(int x,int y){
    return (x>=1&&x<=n&&y>=1&&y<=n);
}
void calc(bool asd[maxn][maxn],int x,int y,int t){
    asd[x][y]=0;
    if(a[x][y]==2)asd[x][y]=1;
    for(int k=0;k<=3;k++){
        int i=x+d[k][0],j=y+d[k][1];
        if(check(i,j)){
            if(a[i][j]==2){
                if(i+d[(b[i][j]+t)&3][0]==x&&j+d[(b[i][j]+t)&3][1]==y)asd[x][y]=1;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,N;
    cin>>N;
    int I=0;
    while (N--) {
        I++;
        int sx=-1,sy=-1;
        scanf("%d",&n);
        memset(flag,0,sizeof(flag));
        for(i=1;i<=n;i++){
            char c;
            scanf("%c",&c);
            for(j=1;j<=n;j++){
                scanf("%c",&c);
                if(c=='.'){
                    a[i][j]=0;
                }
                else if(c=='#'){
                    a[i][j]=1;
                }
                else if(c=='M'){
                    sx=i;
                    sy=j;
                    a[i][j]=0;
                }
                else if(c=='T'){
                    a[i][j]=-1;
                }
                else {
                    a[i][j]=2;
                    if(c=='E')b[i][j]=0;
                    else if(c=='S')b[i][j]=1;
                    else if(c=='W')b[i][j]=2;
                    else if(c=='N')b[i][j]=3;
                }
            }
        }
        node t;
        t.x=sx;t.y=sy;t.t=0;t.now=0;
        flag[sx][sy]=1;
        q.push(t);
        int anst=-1;
        while(!q.empty()) {
            node x=q.front();
            q.pop();
            for(i=0;i<4;i++){
                if(x.now==2){
                    if(check(x.x+d[i][0],x.y+d[i][1])&&!flag[x.x+d[i][0]][x.y+d[i][1]]&&a[x.x+d[i][0]][x.y+d[i][1]]!=1){
                        t.x=x.x+d[i][0];
                        t.y=x.y+d[i][1];
                        t.t=x.t+1;
                        t.now=0;
                        q.push(t);
                        flag[t.x][t.y]=1;
                        if(a[t.x][t.y]==-1){
                            anst=t.t;
                        }
                    }
                }
                else{
                    calc(no,x.x,x.y,x.t);
                    calc(ne,x.x+d[i][0],x.y+d[i][1],x.t);
                    if(check(x.x+d[i][0],x.y+d[i][1])&&!flag[x.x+d[i][0]][x.y+d[i][1]]&&!no[x.x][x.y]&&!ne[x.x+d[i][0]][x.y+d[i][1]]&&a[x.x+d[i][0]][x.y+d[i][1]]!=1){
                        t.x=x.x+d[i][0];
                        t.y=x.y+d[i][1];
                        t.t=x.t+1;
                        t.now=0;
                        q.push(t);
                        flag[t.x][t.y]=1;
                        if(a[t.x][t.y]==-1){
                            anst=t.t;
                        }
                    }
                }
            }
            if(x.now<2){
                t.x=x.x;
                t.y=x.y;
                t.t=x.t+1;
                t.now=x.now+1;
                q.push(t);
            }
        }
        printf("Case #%d: %d\n",I,anst);
    }
    return 0;
}
/*
100000
4
M.W.
..W.
NN..
...T
*/