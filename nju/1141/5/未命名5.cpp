#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<cmath>
using namespace std;
int a[1005][1005];
int main(){
    int i,j,m,n;
    while(cin>>n){
        for(i=1;i<=n;i++)for(j=1;j<=i;j++)scanf("%d",&a[i][j]);
        for(i=n-1;i>=1;i--)for(j=1;j<=i;j++)a[i][j]+=min(a[i+1][j],a[i+1][j+1]);
        cout<<a[1][1]<<endl;
    }
    return 0;
}
