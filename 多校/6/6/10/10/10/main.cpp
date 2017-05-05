//
//  main.cpp
//  10
//
//  Created by wzcjj on 16/8/4.
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
#define maxn 10005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        if(n<=m)printf("%d\n",m-n);
        else {
            for(i=0;i<=32;i++)if(n<(1<<i))break;
            int ans=i+m,now=0,num=0;
            n=n-m;
            while(n){
                int cnt=0;
                while(n>=(1<<cnt)){
                    n-=1<<cnt;
                    now++;
                    cnt++;
                }
                if(ans>now+1+max((1<<cnt)-n-num,0)){
                    ans=now+1+max((1<<cnt)-n-num,0);
                }
                if(n==0&&now<ans)ans=now;
                now++;
                num++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
