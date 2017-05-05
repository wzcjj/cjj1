//
//  main.cpp
//  5
//
//  Created by wzcjj on 16/8/7.
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
#define maxn 1000005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int n,p[maxn<<1],cntl[maxn],cntr[maxn];
char s[maxn],str[maxn<<1];
long long l[maxn],r[maxn],suml[maxn],sumr[maxn];
void manachar(){
    str[0]='$';
    str[1]='#';
    int len=2;
    for(int i=0;i<n;i++){
        str[len++]=s[i];
        str[len++]='#';
    }
    str[len]=0;
    p[0]=1;
    int id=0,ma=1;
    for(int i=1;i<len;i++){
        if(ma>i)p[i]=min(p[2*id-i],ma-i);
        else p[i]=1;
        while(str[i-p[i]]==str[i+p[i]])p[i]++;
        if(i+p[i]>ma){
            ma=i+p[i];
            id=i;
        }
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,N;
    while (scanf("%s",s)!=EOF) {
        n=strlen(s);
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(cntl, 0, sizeof(cntl));
        memset(cntr, 0, sizeof(cntr));
        memset(suml, 0, sizeof(suml));
        memset(sumr, 0, sizeof(sumr));
        manachar();
        for(i=2;i<=n*2;i++){
            if((i&1)&&p[i]==1)continue;
            r[(i-p[i])/2+1]+=(i+p[i])/2-1;
            r[i/2+1]-=(i+1)/2;
            l[(i+p[i])/2-1]+=(i-p[i])/2+1;
            l[(i+1)/2-1]-=i/2;
            cntr[(i-p[i])/2+1]++;
            cntr[i/2]--;
            cntl[(i+p[i])/2-1]++;
            cntl[(i+1)/2]--;
        }
        /*for(i=1;i<=n;i++)printf("%lld ",r[i]);
        printf("\n");
        for(i=1;i<=n;i++)printf("%lld ",l[i]);
        printf("\n");*/
        long long cnt=0,sum=0;
        for(i=1;i<=n;i++){
            sum+=r[i];
            sumr[i]=sum;
            cnt+=cntr[i];
            sum-=cnt;
        }
        cnt=sum=0;
        for(i=n;i>=1;i--){
            suml[i]=l[i]+sum;
            sum+=l[i];
            cnt+=cntl[i];
            sum+=cnt;
        }
        /*for(i=1;i<=n;i++)printf("%lld ",sumr[i]);
        printf("\n");
        for(i=1;i<=n;i++)printf("%lld ",suml[i]);
        printf("\n");*/
        long long ans=0;
        for(i=1;i<=n;i++){
            suml[i]%=P;
            sumr[i]%=P;
        }
        for(i=1;i<n;i++){
            ans=(ans+suml[i]*sumr[i+1])%P;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
