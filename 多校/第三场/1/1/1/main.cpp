//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/7/28.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int a[1000005];
int f[1000005];
int ll[1000005],rr[1000005];
vector<int> b;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    memset(f,0,sizeof(f));
    memset(ll,0,sizeof(ll));
    memset(rr,0,sizeof(rr));
    for(i=2;i<=1000000;i++)if(f[i]==0){
        b.push_back(i);
        f[i]++;
        for(j=2;j*i<=1000000;j++)f[i*j]++;
    }
    for(i=1000000;i>=1;i--){
        for(j=0;(1<<j)+i<=1000000;j++){
            
        }
    }
    while(N--){
        int l,r;
        scanf("%d%d",&l,&r);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
    }
    //std::cout << "Hello, World!\n";
    return 0;
}
