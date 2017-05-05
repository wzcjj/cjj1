//
//  main.cpp
//  2
//
//  Created by wzcjj on 15/12/3.
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
#define maxn 40005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

char s[maxn];
unsigned long long a[maxn];
unsigned long long po[maxn];
int b[maxn];
unsigned long long v[maxn];
inline bool cmp(int x,int y){
    if(v[x]==v[y])return x<y;
    else return v[x]<v[y];
}
int ans,n,m;
bool check(int x){
    for(int i=0;i<n-x+1;i++){
        v[i]=a[i+x]-a[i]*po[x];
        b[i]=i;
    }
    sort(b,b+n-x+1,cmp);
    b[n-x+1]=b[n-x]+1;
    bool flag = false;
    int cnt = 1;
    for(int i=1;i<=n-x+1;i++){
        if(v[b[i]]!=v[b[i-1]]){
            if(cnt>=m){
                if(!flag||ans<b[i-1])ans=b[i-1];
                flag = true;
            }
            cnt=1;
        }
        else cnt++;
    }
    return flag;
}
int main(int argc, const char * argv[]) {
    int i,j,N;
    po[0]=1;
    for(i=1;i<maxn;i++)po[i]=po[i-1]*P;
    while (true) {
        scanf("%d",&m);
        if(m==0)break;
        scanf("%s",s);
        n = strlen(s);
        if(m==1){
            printf("%d 0\n",n);
            continue;
        }
        ans=0;
        a[0]=0;
        for(i=1;i<=n;i++){
            a[i]=a[i-1]*P+s[i-1];
        }
        int l = 0, r = n+1;
        while(l<r){
            int mid = (l+r+1)>>1;
            if(check(mid))l=mid;
            else r=mid-1;
        }
        if(l==0)printf("none\n");
        else printf("%d %d\n",l,ans);
    }
    return 0;
}