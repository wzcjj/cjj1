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
    int i,j,N ,m,n,p,q,k,l;
    cin>>N;
    string s1 = "anniversary";
    while (N--) {
        string s;
        p=0;
        q=s.size()-1;
        cin>>s;
        bool flag = false;
        for(i=1;i<10;i++){
            for(j=i+1;j<=10;j++){
                bool flag1=false;
                for(k=0;k<s.size();k++){
                    flag1=true;
                    for(l=0;l<i;l++)if(k+l>s.size()||s[k+l]!=s1[l]){
                        flag1 = false;
                        break;
                    }
                    if(flag1)break;
                }
                if(!flag1)continue;
                flag1=false;
                for(k=k+l ;k<s.size();k++){
                    flag1=true;
                    for(l=0;l<j-i;l++)if(k+l>s.size()||s[k+l]!=s1[i+l]){
                        flag1 = false;
                        break;
                    }
                    if(flag1)break;
                }
                if(!flag1)continue;
                flag1=false;
                for(k=k+l;k<s.size();k++){
                    flag1=true;
                    for(l=0;l<11-j;l++)if(k+l>s.size()||s[k+l]!=s1[j+l]){
                        flag1 = false;
                        break;
                    }
                    if(flag1)break;
                }
                if(!flag1)continue;
                flag = true;
                break;
            }
            if(flag)break;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}
