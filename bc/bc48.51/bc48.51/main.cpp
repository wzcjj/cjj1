//
//  main.cpp
//  bc48.51
//
//  Created by wzcjj on 15/7/25.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int a[10005];
int main() {
    int i,j,N ,m,n,p,q;
    cin>>N;
    while (N--) {
        cin>>n>>m>>p>>q;
        //for(i=1;i<=n;i++)scanf("%d",&a[i]);
        if(p*m<=q){
            cout<<n*p<<endl;
        }
        else {
            int ans=n/m*q;
            if(n%m*p<q)ans+=n%m*p;
            else ans+=q;
            cout<<ans<<endl;
        }
    }
    //std::cout << "Hello, World!\n";
    return 0;
}
