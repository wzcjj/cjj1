//
//  main.cpp
//  9
//
//  Created by wzcjj on 15/8/4.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 1005
#define P 258280327
#define INF 2100000000
using namespace std;

int a[maxn][maxn];
int m[maxn];
int sum[maxn][maxn];
long long mo[maxn];
char str[maxn];
//string s[maxn];
bool les(int x[],int y[]){
    if(y[0]>x[0])return true;
    else if(y[0]<x[0])return false;
    for(int i=x[0];i>=1;i--){
        if(y[i]>x[i])return true;
        else if(y[i]<x[i])return false;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    int i,j,n,N;
    /*s[1]="b";
    s[2]="a";
    for(i=3;i<=13;i++)s[i]=s[i-1]+s[i-2];
    for(i=1;i<=13;i++)cout<<s[i]<<endl;
    for(i=1;i<=1000;i++){
        for(j=i-1;j>=1;j--){
            if(s[13].substr(0,j)==s[13].substr(i-j,j)){
                //cout<<s[13].substr(0,j)<<endl;cout<<s[13].substr(i-j,j)<<endl;
                cout<<i<<' '<<j<<endl;
                break;
            }
        }
    }*/
    memset(a,0,sizeof(a));
    a[1][0]=a[1][1]=a[2][0]=1;
    a[2][1]=2;
    for(i=3;i<=1001;i++){
        a[i][0]=a[i-1][0];
        for(j=1;j<=a[i][0];j++)a[i][j]=a[i-1][j]+a[i-2][j];
        for(j=1;j<=a[i][0];j++)if(a[i][j]>=10){
            a[i][j+1]++;
            a[i][j]-=10;
        }
        if(a[i][a[i][0]+1]>0)a[i][0]++;
    }
    sum[1][0]=sum[1][1]=1;
    for(i=2;i<=1001;i++){
        sum[i][0]=sum[i-1][0];
        for(j=1;j<=sum[i][0];j++)sum[i][j]=sum[i-1][j]+a[i][j];
        for(j=1;j<=sum[i][0];j++)if(sum[i][j]>=10){
            sum[i][j+1]++;
            sum[i][j]-=10;
        }
        if(sum[i][sum[i][0]+1]>0)sum[i][0]++;
    }
    /*for(i=1;i<=10;i++){
        for(j=a[i][0];j>=1;j--)cout<<a[i][j];
        cout<<endl;
        for(j=sum[i][0];j>=1;j--)cout<<sum[i][j];
        cout<<endl;
        cout<<endl;
    }*/
    mo[1]=1;
    for(i=2;i<=1000;i++)mo[i]=mo[i-1]*10%P;
    cin>>N;
    while (N--) {
        scanf("%*d");
        scanf("%s",str);
        m[0] = strlen(str);
        for(int i = 1;i <= m[0];i++) m[i] = str[m[0]-i] - '0';
        if(m[0]==1&&m[1]==2){
            printf("0\n");
            continue;
        }
        int l=0,r=1001;
        while(l<r-1){
            int mid=(l+r)>>1;
            if(les(sum[mid],m))l=mid;
            else r=mid;
        }
        long long ans[maxn];
        ans[0]=m[0];
        for(i=ans[0];i>=1;i--)ans[i]=m[i]-a[r][i];
        for(i=1;i<ans[0];i++)if(ans[i]<0){
            ans[i]+=10;
            ans[i+1]--;
        }
        while(ans[ans[0]]==0)ans[0]--;
        //for(i=ans[0];i>=1;i--)cout<<ans[i];
       // cout<<endl;
        long long ans1=0;
        for(i=1;i<=ans[0];i++){
            ans1=(ans1+ans[i]*mo[i])%P;
            ans1=(ans1+P)%P;
        }
       // cout<<ans[0]<<endl;
        printf("%lld\n",ans1);
    }
    return 0;
}
