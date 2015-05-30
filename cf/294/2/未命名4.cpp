#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
    int i,j,m,n;
    cin>>n;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n-1;i++)scanf("%d",&b[i]);
    for(i=1;i<=n-2;i++)scanf("%d",&c[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+n);
    sort(c+1,c+n-1);
    for(i=1;i<=n-1;i++)if(a[i]!=b[i])break;
    cout<<a[i]<<endl;
    for(i=1;i<=n-2;i++)if(b[i]!=c[i])break;
    cout<<b[i]<<endl;
    return 0;
}
