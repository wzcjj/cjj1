#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[105],v[105],s[105];
int main(){
    int i,j,m,n,t;
    cin>>n>>m>>t;
    for(i=1;i<=n;i++)cin>>a[i];
    memset(v,0,sizeof(v));
    memset(s,0,sizeof(s));
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            s[j]+=(v[j]+v[j]+a[j]*t)*t/2;
            v[j]+=a[j]*t;
        }
        long long max=0,z=0;
        for(j=1;j<=n;j++)if(s[j]>max){
            max=s[j];
            z=j;
        }
        if(i!=m)cout<<z<<' ';
        else cout<<z<<endl;
        v[z]=0;
    }
    system("pause");
    return 0;
}
