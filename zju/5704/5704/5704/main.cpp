//
//  main.cpp
//  5704
//
//  Created by wzcjj on 16/4/23.
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
#define maxn 105
#define P 1000000007
#define INF 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define abs(x) ((x >= 0) ? x : -(x))
using namespace std;

char a[maxn][maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for(i=2;i<=n+1;i++){
            char c;
            scanf("%c",&c);
            for(j=2;j<=m+1;j++){
                scanf("%c",&a[i][j]);
            }
        }
        int ans=0;
        for(i=2;i<=n+1;i++){
            for(j=2;j<=m+1;j++){
                if(a[i][j]=='O')ans++;
                else{
                    int x,y;
                    bool flag=false;
                    switch (a[i][j]) {
                        case '/':
                            x=-1;
                            y=1;
                            break;
                            
                        case '|':
                            x=-1;
                            y=0;
                            break;
                            
                        case '\\':
                            x=y=-1;
                            break;
                            
                        case '(':
                            x=-2;
                            y=1;
                            break;
                            
                        case ')':
                            x=-2;
                            y=-1;
                            break;
                            
                        case '.':
                            flag=true;
                            break;
                            
                        default:
                            break;
                    }
                    if(!flag){
                        if(a[i+x][j+y]!='O'){
                            ans++;
                            a[i+x][j+y]='O';
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
