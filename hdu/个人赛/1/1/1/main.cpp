//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/12/26.
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
#define maxn 10005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

char s[105][30];
bool flag[105];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%d\n",&n)!=EOF) {
        for(i=1;i<=n;i++){
            scanf("%s",s[i]);
            m=strlen(s[i]);
            for(j=0;j<m;j++){
                if(s[i][j]<='Z')s[i][j]+='a'-'A';
            }
        }
        memset(flag, 0, sizeof(flag));
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                int cnt=0;
                int m=strlen(s[i]);
                if(m==strlen(s[j])){
                    for(int k=0;k<m;k++){
                        if(s[i][k]==s[j][k])cnt++;
                    }
                    if(cnt>2){
                        flag[i]=flag[j]=true;
                    }
                }
            }
        }
        int ans=0;
        for(i=1;i<=n;i++)ans+=flag[i];
        printf("%d\n",ans);
    }
    return 0;
}
