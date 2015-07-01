#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<iomanip> 
using namespace std;
int a[200005];
int main(){
    int i,j,m,n;
    cin>>n>>m;
    for(i=1;i<=2*n;i++)scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    int t=a[n+1];
    if(t>a[1]*2)t=a[1]*2;
    double ans=1.5*t*n;
    if(ans>m)ans=m;
    printf("%.6lf\n",ans);
    return 0;
} 
