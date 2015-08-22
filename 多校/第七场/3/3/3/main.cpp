//
//  main.cpp
//  3
//
//  Created by wzcjj on 15/8/11.
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
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;

int p[maxn * 2];
int a[maxn * 2],n;

void manachar(){
    int mx = 0, id;
    p[0] = 0;
    for(int i = 1; i<=2*n+1; ++i){
        if(mx > i){
            p[i] = min(mx - i, p[2*id - i]);
        }
        else{
            p[i] = 1;
        }
        while(a[i - p[i]] == a[i + p[i]]){
            ++p[i];
        }
        if(p[i] + i > mx){
            mx = p[i] + i;
            id = i;
        }
    }
}

int main(int argc, const char * argv[]) {
    int i,j,m,N,I=0;
    cin>>N;
    while (N--) {
        I++;
        scanf("%d",&n);
        a[1]=-1;
        for(i=1;i<=n;i++){
            scanf("%d",&a[2*i]);
            a[2*i+1]=-1;
        }
        manachar();
        //for(i=1;i<=2*n+1;i++)cout<<p[i]<<endl;
        int ans=1;
        for(i=1;i<=2*n+1;i+=2)for(j=p[i];j>=ans;j-=2){
            if(j+i-1<=2*n+1&&p[j+i-1]>=j&&ans<j){
                ans=j;
            }
        }
        printf("Case #%d: %d\n",I,ans/2*3);
    }
    return 0;
}

