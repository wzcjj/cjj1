//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/10/23.
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
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;

int a[4][10],b[4][10];
int ans[maxn],cnt;
bool shisanyao(){
    if(a[0][1]>=1&&a[0][2]>=1&&a[0][3]>=1&&a[0][4]>=1&&a[0][5]>=1&&a[0][6]>=1&&a[0][7]>=1&&a[1][1]>=1&&a[1][9]>=1&&a[2][1]>=1&&a[2][9]>=1&&a[3][1]>=1&&a[3][9]>=1&&(a[0][1]>1||a[0][2]>1||a[0][3]>1||a[0][4]>1||a[0][5]>1||a[0][6]>1||a[0][7]>1||a[1][1]>1||a[1][9]>1||a[2][1]>1||a[2][9]>1||a[3][1]>1||a[3][9]>1))return true;
    else return false;
}
bool qidui(){
    int sum=0;
    for(int i=0;i<=3;i++){
        for(int j=1;j<=9;j++){
            if(a[i][j]>=2)sum++;
        }
    }
    if(sum==7)return true;
    else return false;
}
bool si(int x){
    if(x==0)return true;
    for(int i=0;i<=3;i++){
        for(int j=1;j<=9;j++){
            if(a[i][j]>=3){
                a[i][j]-=3;
                if(si(x-1)){
                    a[i][j]+=3;
                    return true;
                }
                a[i][j]+=3;
            }
        }
    }
    int sum=0;
    memset(b,0,sizeof(b));
    for(int i=1;i<=3;i++){
        for(int j=1;j<=7;j++){
            while(a[i][j]>=1&&a[i][j+1]>=1&&a[i][j+2]>=1){
                a[i][j]--;
                a[i][j+1]--;
                a[i][j+2]--;
                b[i][j]++;
                b[i][j+1]++;
                b[i][j+2]++;
                sum++;
            }
        }
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=9;j++){
            a[i][j]+=b[i][j];
        }
    }
    if(sum==x)return true;
    else return false;
}
bool sijiaer(){
    for(int i=0;i<=3;i++){
        for(int j=1;j<=9;j++){
            if(a[i][j]>=2){
                a[i][j]-=2;
                if(si(4)){
                    a[i][j]+=2;
                    //cout<<i<<' '<<j<<endl;
                    return true;
                }
                a[i][j]+=2;
            }
        }
    }
    return false;
}
bool solve(){
    if(shisanyao())return true;
    if(qidui())return true;
    if(sijiaer())return true;
    return false;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        memset(a,0,sizeof(a));
        cnt=0;
        for(i=1;i<=13;i++){
            char s[5];
            scanf("%s",s);
            int x,y;
            if(s[1]=='c'){
                x=0;
            }
            else if(s[1]=='m'){
                x=1;
            }
            else if(s[1]=='s'){
                x=2;
            }
            else x=3;
            y=s[0]-'0';
            a[x][y]++;
        }
        for(i=1;i<=3;i++){
            for(j=1;j<=9;j++){
                a[i][j]++;
                if(solve()){
                    ans[++cnt]=i*10+j;
                }
                a[i][j]--;
            }
        }
        for(j=1;j<=7;j++){
            a[0][j]++;
            if(solve()){
                ans[++cnt]=j;
            }
            a[0][j]--;
            
        }
        if(cnt){
            printf("%d",cnt);
            for(i=1;i<=cnt;i++){
                printf(" %d",ans[i]%10);
                if(ans[i]/10==0)printf("c");
                else if(ans[i]/10==1)printf("m");
                else if(ans[i]/10==2)printf("s");
                else if(ans[i]/10==3)printf("p");
            }
            printf("\n");
        }
        else printf("Nooten\n");
    }
    return 0;
}
