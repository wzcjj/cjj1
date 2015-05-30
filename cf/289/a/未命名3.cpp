#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[15][15];
int main(){
    int i,j,m,n;
    cin>>n;
    memset(a,0,sizeof(a));
    a[1][1]=1;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(i!=1||j!=1)a[i][j]=a[i-1][j]+a[i][j-1];
    cout<<a[n][n];
    return 0;
}
