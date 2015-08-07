//
//  main.cpp
//  bc48.52
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
    int i,j,N,m,n;
    cin>>N;
    for(i=1;i<=10000;i++)a[i]=3*i*(i-1)+1;
    while (N--) {
        cin>>n;
        int ans=0;
        int l=0,r=10000;
        while(l<r-1){
            int mid=(l+r)>>1;
            if(a[mid]>n)r=mid;
            else l=mid;
        }
        for(i=l;i>=1;i--){
            while(n>=a[i]){
                n-=a[i];
                ans++;
            }
            if(n==0)break;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
