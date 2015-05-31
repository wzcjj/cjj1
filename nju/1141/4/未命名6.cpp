#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
int a[3000005];
int main(){
    int i,j,m,n;
    n=0;
    while(scanf("%d",&i)!=EOF)a[++n]=i;
    sort(a+1,a+1+n);
    for(i=1;i<n;i++)printf("%d ",a[i]);
    printf("%d\n",a[n]);
    return 0;
}
