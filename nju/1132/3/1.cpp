#include<cstdio>
#include<iostream>
using namespace std;
int a[1000005],lef[1000005],righ[1000005];
long long mergee(int l,int r){
    int i,j;
    long long ans;
    for(i=l;i<=(l+r)/2;i++)lef[i-l+1]=a[i];
    for(i=(l+r)/2+1;i<=r;i++)righ[i-(l+r)/2]=a[i];
    i=1;j=1;ans=0;
    for(int k=l;k<=r;k++)if(i<=(r+l)/2-l+1&&(j>r-(r+l)/2||lef[i]<=righ[j])){
        a[k]=lef[i++];
    }
    else{
        ans+=(r+l)/2-l-i+2;
        a[k]=righ[j++];
    }
    return ans;
}
long long mergesort(int l,int r){
    if(l==r)return 0;
    long long ans=0;
    ans+=mergesort(l,(l+r)/2);
    ans+=mergesort((l+r)/2+1,r);
    ans+=mergee(l,r);
    return ans;
}
int main() {
    int i,j,m,n;
    cin>>n;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    long long ans;
    ans=mergesort(1,n);
    cout<<ans<<endl;
    return 0;
}
