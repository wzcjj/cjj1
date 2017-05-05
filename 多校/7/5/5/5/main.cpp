//
//  main.cpp
//  5
//
//  Created by wzcjj on 16/8/9.
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
#define maxn 1005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct node{
    int i,v;
    friend bool operator<(node x,node y){
        return x.v<y.v;
    }
};
node a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I=0;
    cin>>N;
    while (N--) {
        I++;
        m=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            a[i].i=i;
            scanf("%d",&a[i].v);
            m+=a[i].v;
        }
        sort(a+1, a+1+n);
        bool flag=0;
        for(i=1;i<=n;i++){
            if(a[i].v>=i){
                flag=1;
                break;
            }
        }
        if(flag){
            printf("Case #%d: No\n",I);
            continue;
        }
        printf("Case #%d: Yes\n",I);
        printf("%d\n",m);
        for(i=2;i<=n;i++){
            for(j=1;j<=a[i].v;j++){
                printf("%d %d\n",a[i].i,a[j].i);
            }
        }
    }
    return 0;
}
