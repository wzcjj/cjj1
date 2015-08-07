//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/7/30.
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
#define maxn 100005
#define P 1000000007
#define INF 2100000000
using namespace std;

bool a[maxn];
int b[maxn];
bool f[10];
int l,r;
int ans,now;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(i=1;i<=100000;i++){
        j=i;
        bool flag =false;
        memset(f,0,sizeof(f));
        while(j){
            int t=j%10;
            j/=10;
            if(f[t]){
                flag=true;
                break;
            }
            f[t]=true;
        }
        a[i]=!flag;
    }
    for(i=1;i<=100000;i++)b[i]=a[i]+b[i-1];
    while (N--) {
        scanf("%d%d",&l,&r);
        printf("%d\n",b[r]-b[l-1]);
    }
    return 0;
}
