#include<cstdio>
#include<iostream>
using namespace std;
short a[10000005];
int main(){
    int i,n,max,maxi,maxl,ans;
    cin>>n;
    max=ans=maxi=0;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)if(max<a[i]){
        max=a[i];
        maxi=i;
    }
    maxl=0;
    for(i=1;i<maxi;i++)
        if(a[i]>maxl)maxl=a[i];
        else ans+=maxl-a[i];
    maxl=0;
    for(i=n;i>maxi;i--)
        if(a[i]>maxl)maxl=a[i];
        else ans+=maxl-a[i];
    cout<<ans<<endl;
    system("pause");
    return 0;
}
