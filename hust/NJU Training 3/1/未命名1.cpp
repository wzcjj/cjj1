#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a[105];
int main(){
    int i,j,m,n,N;
    cin>>N;
    for(int I=1;I<=N;I++){
        cin>>n>>m;
        for(i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+1+n);
        int ans=1;
        for(i=1;i<=n-1;i++)if(a[i+1]-a[i]>m)ans++;
        cout<<"Case #"<<I<<": "<<ans<<endl;
    }
    return 0;
}

         
