//
//  main.cpp
//  8
//
//  Created by wzcjj on 16/10/6.
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
#define maxn 200005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

deque<int> b;
int a[2*maxn];
char s[10];
void swap(int &x,int &y){
    int t=x;
    x=y;
    y=t;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I=0;
    cin>>N;
    while (N--) {
        I++;
        printf("Case #%d:\n",I);
        int l=maxn,r=maxn-1;
        int re=1;
        b.clear();
        scanf("%d",&n);
        for(j=1;j<=n;j++){
            scanf("%s",s);
            if(s[2]=='S'){
                int x;
                scanf("%d",&x);
                r+=re;
                a[r]=x;
                if(!x){
                    if(re==1)b.push_back(r);
                    else b.push_front(r);
                }
            }
            else if(s[2]=='P'){
                if(!a[r]){
                    if(re==1)b.pop_back();
                    else b.pop_front();
                }
                r-=re;
            }
            else if(s[2]=='V'){
                re=-re;
                swap(l,r);
            }
            else {
                if(l==r+re){
                    printf("Invalid.\n");
                }
                else {
                    int x;
                    bool ans;
                    if(b.empty()){
                        if((l-r)&1)ans=0;
                        else ans=1;
                    }
                    else {
                        if(re==1)x=b.front();
                        else x=b.back();
                        if((x-l)&1){
                            if(r==x)ans=1;
                            else ans=0;
                        }
                        else {
                            if(r==x)ans=0;
                            else ans=1;
                        }
                    }
                    if(ans)printf("1\n");
                    else printf("0\n");
                }
            }
        }
    }
    return 0;
}
