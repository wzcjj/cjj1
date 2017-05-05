//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/7/31.
//  Copyright (c) 2016年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define max(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

const int maxn=(1<<16)+200;
const long long MOD=1e9+7;
long long ans;
vector<int>  e[maxn];
int f[maxn];
int w[maxn];

int n;
long long dp[maxn];
int mx[maxn];

int cmx[maxn];
int fill()
{
    for (int i=1;i<maxn;i++)
    {
        int tp=0;
        int cp=1;
        while (cp<=i)
        {
            tp|=cp;
            cp<<=1;
        }
        cmx[i]=tp;
    }
    return 0;
}

char OP[10];
int op;
int oper(int x,int y)
{
    if (op==0) return x&y;
    else if (op==1) return x|y;
    else if (op==2) return x^y;
    return 0;
}

int main()
{
    fill();
    //for (int i=0;i<140;i++)
    //    cout<<cmx[i]<<endl;
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        memset(dp,0,sizeof(dp));
        memset(mx,0,sizeof(mx));
        scanf("%d%s",&n,OP);
        if (strcmp(OP,"AND")==0) op=0;
        else if (strcmp(OP,"OR")==0) op=1;
        else if (strcmp(OP,"XOR")==0) op=2;
        for (int j=1;j<=n;j++)
            scanf("%d",&w[j]);
        for (int j=2;j<=n;j++)
        {
            scanf("%d",&f[j]);
        }
        for (int j=1;j<=n;j++)
        {
            if (j!=1) mx[j]=max(mx[f[j]],cmx[w[j]]);
            else mx[j]=cmx[w[j]];
        }
        ans=0;
        for (int j=1;j<=n;j++)
        {
            int cp=f[j];
            while (cp!=0)
            {
                dp[j]=max(dp[cp]+oper(w[j],w[cp]),dp[j]);
                if (dp[j]-dp[cp]>=mx[j]) break;
                cp=f[cp];
            }
            //dp[j]=dp[j]%MOD;
            ans=(ans+((long long)j)*((dp[j]+w[j])%MOD))%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}