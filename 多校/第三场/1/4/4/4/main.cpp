//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/7/28.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

char a[60][60];
string s[60];
int min(unsigned long x,int y){
    return x<y?x:y;
}
int abs(int x){
    if(x>=0)return x;
    else return -x;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    char c;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&n);
        memset(a, 0, sizeof(a));
        for(i=1;i<=n;i++){
            /*scanf("%c",&c);
            for(j=1;j<=n;j++){
                scanf("%c",&a[i][j]);
            }*/
            cin>>s[i];
            for(j=0;j<s[i].size();j++)a[i][j+1]=s[i][j];
        }
        //for(i=1;i<=n;i++)for(j=1;j<=n;j++)cout<<a[i][j];
        int ans=0;
        if(s[1].size()>=n){
            for(i=1;i<min(s[1].size(),n);i++){
                for(j=1;j<=i;j++)if((a[n-i+j][j]=='R'||a[n-i+j][j]=='G')&&(a[n-i+j-1][j-1]!='R'&&a[n-i+j-1][j-1]!='G'))ans++;
            }
            for(i=1;i<min(s[1].size(),n);i++){
                for(j=1;j<=i;j++)if((a[j][n-i+j+(s[1].size()-n)]=='R'||a[j][n-i+j+(s[1].size()-n)]=='G')&&(a[j-1][n-i+j-1+(s[1].size()-n)]!='R'&&a[j-1][n-i+j-1+(s[1].size()-n)]!='G'))ans++;
            }
            for(i=1;i<min(s[1].size(),n);i++){
                for(j=1;j<=i;j++)if((a[n-i+j][n-j+1+(s[1].size()-n)]=='B'||a[n-i+j][n-j+1+(s[1].size()-n)]=='G')&&(a[n-i+j-1][n-j+2+(s[1].size()-n)]!='B'&&a[n-i+j-1][n-j+2+(s[1].size()-n)]!='G'))ans++;
            }
            for(i=1;i<min(s[1].size(),n);i++){
                for(j=1;j<=i;j++)if((a[j][i-j+1]=='B'||a[j][i-j+1]=='G')&&(a[j-1][i-j+2]!='B'&&a[j-1][i-j+2]!='G'))ans++;
            }
            for(i=1;i<=s[1].size()-n+1;i++){
                for(j=1;j<=n;j++)if((a[j][i+j-1]=='R'||a[j][i+j-1]=='G')&&(a[j-1][i+j-2]!='R'&&a[j-1][i+j-2]!='G'))ans++;
                for(j=1;j<=n;j++)if((a[n-j+1][i+j-1]=='B'||a[n-j+1][i+j-1]=='G')&&(a[n-j+2][i+j-2]!='B'&&a[n-j+2][i+j-2]!='G'))ans++;
            }
            printf("%d\n",ans);
        }
        else{
            for(i=1;i<min(s[1].size(),n);i++){
                for(j=1;j<=i;j++)if((a[n-i+j][j]=='R'||a[n-i+j][j]=='G')&&(a[n-i+j-1][j-1]!='R'&&a[n-i+j-1][j-1]!='G'))ans++;
            }
            for(i=1;i<min(s[1].size(),n);i++){
                for(j=1;j<=i;j++)if((a[j][s[1].size()-i+j]=='R'||a[j][s[1].size()-i+j]=='G')&&(a[j-1][s[1].size()-i+j-1]!='R'&&a[j-1][s[1].size()-i+j-1]!='G'))ans++;
            }
            for(i=1;i<min(s[1].size(),n);i++){
                for(j=1;j<=i;j++)if((a[n-i+j][s[1].size()-j+1]=='B'||a[n-i+j][s[1].size()-j+1]=='G')&&(a[n-i+j-1][s[1].size()-j+2]!='B'&&a[n-i+j-1][s[1].size()-j+2]!='G'))ans++;
            }
            for(i=1;i<min(s[1].size(),n);i++){
                for(j=1;j<=i;j++)if((a[j][i-j+1]=='B'||a[j][i-j+1]=='G')&&(a[j-1][i-j+2]!='B'&&a[j-1][i-j+2]!='G'))ans++;
            }
            for(i=1;i<=n-s[1].size()+1;i++){
                for(j=1;j<=s[1].size();j++)if((a[j+i-1][j]=='R'||a[j+i-1][j]=='G')&&(a[j-1+i-1][j-1]!='R'&&a[j-1+i-1][j-1]!='G'))ans++;
                for(j=1;j<=s[1].size();j++)if((a[n-j+1-i+1][j]=='B'||a[n-j+1-i+1][j]=='G')&&(a[n-j+2-i+1][j-1]!='B'&&a[n-j+2-i+1][j-1]!='G'))ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
