//
//  main.cpp
//  7
//
//  Created by wzcjj on 15/8/13.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 105
#define P 1000000007
#define INF 2100000000
using namespace std;

struct node{
    int t,x,y;
};
int a[maxn][maxn],b[maxn][maxn],ans[5*maxn];
bool fl[5*maxn];
node d[5*maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&b[i][j]);
        for(i=1;i<=m;i++){
            char c[5];
            scanf("%s",c);
            if(c[0]=='H'){
                d[i].t=1;
                scanf("%d%d",&d[i].x,&d[i].y);
            }
            else{
                d[i].t=2;
                scanf("%d%d",&d[i].x,&d[i].y);
            }
        }
        memset(fl,0,sizeof(fl));
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++)if(!fl[j]){
                if(d[j].t==1){
                    int co=0;
                    bool flag=false;
                    for(k=1;k<=n;k++){
                        if(co==0){
                            co=b[d[j].x][k];
                        }
                        if(co!=0){
                            if(co!=b[d[j].x][k]&&b[d[j].x][k]!=0){
                                flag=true;
                                break;
                            }
                        }
                    }
                    if(!flag&&(co==d[j].y||co==0)){
                        ans[j]=m-i+1;
                        fl[j]=true;
                        for(k=1;k<=n;k++)b[d[j].x][k]=0;
                        break;
                    }
                }
                else{
                    int co=0;
                    bool flag=false;
                    for(k=1;k<=n;k++){
                        if(co==0){
                            co=b[k][d[j].x];
                        }
                        if(co!=0)if(co!=b[k][d[j].x]&&b[k][d[j].x]!=0){
                            flag=true;
                            break;
                        }
                    }
                    if(!flag&&(co==d[j].y||co==0)){
                        ans[j]=m-i+1;
                        fl[j]=true;
                        for(k=1;k<=n;k++)b[k][d[j].x]=0;
                        break;
                    }
                }
            }
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                if(ans[j]==i){
                    if(i<m)printf("%d ",j);
                    else printf("%d\n",j);
                    break;
                }
            }
        }
    }
    return 0;
}
