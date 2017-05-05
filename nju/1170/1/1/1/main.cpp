//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/1/13.
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
#define maxn 500
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

char a[maxn][maxn];
int n,m;
char s[maxn];
bool check(int x,int y){
    if((x>0&&x<=n)&&(y>0&&y<=m))return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    int i,j,N;
    scanf("%d%d\n",&n,&m);
    memset(a,0,sizeof(a));
    while(scanf("%s",s)!=EOF){
        if(s[0]=='P'){
            if(s[1]=='O'){
                int x,y;
                scanf("%d%d\n",&x,&y);
                if(!check(x,y))continue;
                if(a[x][y]==0||a[x][y]=='o'){
                    a[x][y]='o';
                }
                else a[x][y]='*';
            }
            else{
                for(i=1;i<=n;i++){
                    a[i][0]='-';
                    a[i][m+1]='-';
                }
                for(i=1;i<=m;i++){
                    a[0][i]='|';
                    a[n+1][i]='|';
                }
                a[0][0]=a[0][m+1]=a[n+1][0]=a[n+1][m+1]='+';
                for(i=0;i<=m+1;i++){
                    for(j=0;j<=n+1;j++){
                        if(a[j][i]==0)printf(" ");
                        else printf("%c",a[j][i]);
                    }
                    printf("\n");
                }
                break;
            }
        }
        else if(s[0]=='T'){
            int x,y;
            scanf("%d%d %s\n",&x,&y,s);
            int t=strlen(s);
            for(i=0;i<t;i++){
                if(!check(x+i,y))continue;
                if(a[x+i][y]==0||a[x+i][y]==s[i])a[x+i][y]=s[i];
                else a[x+i][y]='*';
            }
        }
        else if(s[0]=='C'){
            int x1,y1,x2,y2,minx,miny,maxx,maxy;
            scanf("%d%d%d%d\n",&x1,&y1,&x2,&y2);
            minx=min(x1,x2);
            maxx=max(x1,x2);
            miny=min(y1,y2);
            maxy=max(y1,y2);
            for(i=minx;i<=maxx;i++){
                for(j=miny;j<=maxy;j++){
                    if(!check(i,j))continue;
                    a[i][j]=0;
                }
            }
        }
        else {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d\n",&x1,&y1,&x2,&y2);
            if(x1==x2){
                for(i=min(y1,y2);i<=max(y1,y2);i++){
                    if(!check(x1,i))continue;
                    if(a[x1][i]==0||a[x1][i]=='|')a[x1][i]='|';
                    else if(a[x1][i]=='-'||a[x1][i]=='+')a[x1][i]='+';
                    else a[x1][i]='*';
                }
            }
            else if(y1==y2){
                for(i=min(x1,x2);i<=max(x1,x2);i++){
                    if(!check(i,y1))continue;
                    if(a[i][y1]==0||a[i][y1]=='-')a[i][y1]='-';
                    else if(a[i][y1]=='|'||a[i][y1]=='+')a[i][y1]='+';
                    else a[i][y1]='*';
                }
            }
            else if((x1<x2&&y1<y2)||(x1>x2&&y1>y2)){
                int minx=min(x1,x2),miny=min(y1,y2);
                for(i=0;i<=max(x1-x2,x2-x1);i++){
                    if(!check(minx+i,miny+i))continue;
                    if(a[minx+i][miny+i]==0||a[minx+i][miny+i]=='\\')a[minx+i][miny+i]='\\';
                    else if(a[minx+i][miny+i]=='/'||a[minx+i][miny+i]=='x')a[minx+i][miny+i]='x';
                    else a[minx+i][miny+i]='*';
                }
            }
            else {
                int minx=min(x1,x2),maxy=max(y1,y2);
                for(i=0;i<=max(x1-x2,x2-x1);i++){
                    if(!check(minx+i,maxy-i))continue;
                    if(a[minx+i][maxy-i]==0||a[minx+i][maxy-i]=='/')a[minx+i][maxy-i]='/';
                    else if(a[minx+i][maxy-i]=='\\'||a[minx+i][maxy-i]=='x')a[minx+i][maxy-i]='x';
                    else a[minx+i][maxy-i]='*';
                }
            }
        }
    }
    return 0;
}
