#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <cmath>
using namespace std;
int a[1005];
int main(){
    int i,j,m,n;
    int I=0;
    memset(a,0,sizeof(a));
    a[1]=1;
    for(i=2;i<=1000;i++)for(j=1;j<=i-1;j++)if((i-j-1)%j==0)a[i]=(a[i]+a[j])%1000000007;
    while(cin>>n){
        I++;
        printf("Case %d: %d\n",I,a[n]);
    }
    return 0;
}
