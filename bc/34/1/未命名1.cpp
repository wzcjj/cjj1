#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[105],b[105];
int main(){
    int i,m,n;
    while(cin>>n>>m){
    for(i=1;i<=m;i++)cin>>a[i]>>b[i];
    int min=10000000;
    for(i=1;i<=m;i++)if(((n-1)/a[i]+1)*b[i]<min)min=((n-1)/a[i]+1)*b[i];
    cout<<min<<endl;
}
    return 0;
}
