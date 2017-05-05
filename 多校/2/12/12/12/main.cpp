//
//  main.cpp
//  12
//
//  Created by wzcjj on 16/7/21.
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

char s1[maxn],s2[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    scanf("%d",&N);
    while (N--) {
        scanf("%d%d",&n,&m);
        scanf("%s%s",s1,s2);
        for(i=0;i<n-m+1;i++){
            int z=1;
            for(j=0;j<m;j++){
                if(s1[j+i]!=s2[j]){
                    if(s1[j+i]==s2[j+1]&&s1[j+i+1]==s2[j])j++;
                    else {
                        z=0;
                        break;
                    }
                }
            }
            printf("%d",z);
        }
        for(i=n-m+1;i<n;i++)printf("0");
        printf("\n");
    }
    return 0;
}
