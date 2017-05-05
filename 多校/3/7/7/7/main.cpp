//
//  main.cpp
//  7
//
//  Created by wzcjj on 16/7/26.
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

vector<int> a[maxn];
bool flag[maxn];
int ans;
int dfs1(int x,int fa){
    if(a[x].size()==1){
        ans++;
        return 1;
    }
    int sum=0;
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa){
        int y=dfs1(a[x][i],x);
        sum+=y;
    }
    if(sum&1){
        ans++;
        return 1;
    }
    else {
        if(fa!=-1)ans+=2;
        return 2;
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        //memset(b,0,sizeof(b));
        scanf("%d",&n);
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        if(n==1){
            printf("0\n");
            continue;
        }
        else if(n==2){
            printf("1\n");
            continue;
        }
        int sum=0;
        for(i=1;i<=n;i++)if(a[i].size()==1)sum++;
        if(sum&1){
            memset(flag, 0, sizeof(flag));
            int mi=INF;
            for(i=1;i<=n;i++)if(a[i].size()==1){
                int fa=-1,cnt=0;
                j=i;
                while(a[j].size()<3){
                    for(int k=0;k<a[j].size();k++)if(a[j][k]!=fa){
                        fa=j;
                        j=a[j][k];
                        cnt++;
                        break;
                    }
                }
                if(!flag[j]){
                    ans=0;
                    dfs1(j,fa);
                    flag[j]=1;
                    ans+=cnt-2;
                    if(ans<mi)mi=ans;
                }
            }
            printf("%d\n",mi);
        }
        else {
            ans=0;
            for(i=1;i<=n;i++)if(a[i].size()!=1){
                dfs1(i,-1);
                break;
            }
            printf("%d\n",ans);
        }
        
    }
    return 0;
}
/*
 8
 1 2
 1 3
 2 4
 2 5
 2 6
 3 7
 3 8
*/