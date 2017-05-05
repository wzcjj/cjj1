//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/8/18.
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
#define maxn 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

long long a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(i=1;i<=m;i++){
            int l1,l2,r1,r2;
            double ans;
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            if(l1>r2||l2>r1){
                if(l1>r2){
                    int t=l1;
                    l1=l2;
                    l2=t;
                    t=r1;
                    r1=r2;
                    r2=t;
                }
                if(r1-l1>r2-l2){
                    int t=r1-l1-r2+l2;
                    int s=r1-t/2;
                    if((t&1)==0){
                        ans=(a[s]+a[s+1])/2.0;
                    }
                    else {
                        ans=a[s];
                    }
                }
                else if(r1-l1<r2-l2){
                    int t=r2-l2-r1+l1;
                    int s=l2+(t-1)/2;
                    if((t&1)==0){
                        ans=(a[s]+a[s+1])/2.0;
                    }
                    else {
                        ans=a[s];
                    }
                }
                else {
                    ans=(a[r1]+a[l2])/2.0;
                }
            }
            else {
                if(l1>l2){
                    int t=l1;
                    l1=l2;
                    l2=t;
                }
                if(r1>r2){
                    int t=r1;r1=r2;r2=t;
                }
                int l=l1,r=r2,suml,sumr;
                while(l<r-1){
                    int mid=(l+r)>>1;
                    if(mid>=l2&&mid<=r1){
                        suml=(mid-l2+1)*2+l2-l1;
                        sumr=(r1-mid)*2+r2-r1;
                    }
                    else if(mid<l2){
                        suml=mid-l1+1;
                        sumr=r2-mid+r1-l2+1;
                    }
                    else {
                        suml=mid-l1+1+r1-l2+1;
                        sumr=r2-mid;
                    }
                    if(suml<=sumr)l=mid;
                    else r=mid;
                }
                int t=l;
                if(t>=l2&&t<=r1){
                    suml=(t-l2+1)*2+l2-l1;
                    sumr=(r1-t)*2+r2-r1;
                }
                else if(t<l2){
                    suml=t-l1+1;
                    sumr=r2-t+r1-l2+1;
                }
                else {
                    suml=t-l1+1+r1-l2+1;
                    sumr=r2-t;
                }
                if(suml==sumr){
                    ans=(a[t]+a[t+1])/2.0;
                }
                else if(suml<sumr){
                    ans=a[t+1];
                }
                else {
                    ans=a[t];
                }
            }
            printf("%.1lf\n",ans);
        }
    }
    return 0;
}
