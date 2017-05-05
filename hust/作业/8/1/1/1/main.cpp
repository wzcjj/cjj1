//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/12/2.
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
#define maxn 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -x)
using namespace std;

vector<int> a[maxn];
vector<int> b[maxn];
char s1[maxn][30],s2[maxn][100];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    N=0;
    while (true) {
        scanf("%c",&s1[N+1][0]);
        if(s1[N+1][0]=='@'){
            scanf("%*s");
            break;
        }
        m=1;
        while(s1[N+1][m-1]!=']')scanf("%c",&s1[N+1][m++]);
        scanf("%*c");
        N++;
        gets(s2[N]);
        n=strlen(s2[N]);
        int val = 0;
        for(i=0;i<m;i++){
            val+=i*s1[N][i];
        }
        a[val&0xffff].push_back(N);
        val=0;
        for(i=0;i<n;i++){
            val+=i*s2[N][i];
        }
        b[val&0xffff].push_back(N);
    }
    scanf("%d\n",&n);
    for(i=1;i<=n;i++){
        char s[100];
        gets(s);
        if(s[0]=='['){
            m=strlen(s);
            int val =0;
            for(j=0;j<m;j++){
                val+=j*s[j];
            }
            val = val & 0xffff;
            bool flag=false;
            for(j=0;j<a[val].size();j++){
                if(strcmp(s1[a[val][j]],s)==0){
                    flag = true;
                    printf("%s\n",s2[a[val][j]]);
                    break;
                }
            }
            if(!flag){
                printf("what?\n");
            }
        }
        else {
            m=strlen(s);
            int val =0;
            for(j=0;j<m;j++){
                val+=j*s[j];
            }
            val = val & 0xffff;
            bool flag=false;
            for(j=0;j<b[val].size();j++){
                if(strcmp(s2[b[val][j]],s)==0){
                    flag = true;
                    int t=strlen(s1[b[val][j]]);
                    for(int k=1;k<t-1;k++){
                        printf("%c",s1[b[val][j]][k]);
                    }
                    printf("\n");
                    break;
                }
            }
            if(!flag){
                printf("what?\n");
            }
        }
    }
    return 0;
}
