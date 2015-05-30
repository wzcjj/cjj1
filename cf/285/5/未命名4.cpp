#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005];
bool canl[100005],canr[100005];
int le[100005];
int main(){
    int i,j,m,n;
    long long ans=0;
    cin>>n;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(le,0,sizeof(le));
    for(i=1;i<=n;i++)le[a[i]]++;
    int t=0;
    for(i=1;i<=n;i++)if(le[i]%2==1)t++;
    if(t>n%2){
        cout<<0;
        return 0;
    };
    canl[0]=true;
    canr[n+1]=true;
    le[0]=0;
    for(i=1;i<=n;i++)if(canl[i-1]&&a[i]==a[n-i+1])canl[i]=true;
    else canl[i]=false;
    for(i=n;i>=1;i--)if(canr[i+1]&&a[i]==a[n-i+1])canr[i]=true;
    else canr[i]=false;
    for(i=1;i<=n;i++){
        int l=le[i-1],r=i+1;
        while(l<r-1){
            int mid=(l+r)>>1;
            if(canl[mid-1]&&canr[i+1])l=mid;
            else r=mid;
        }
        le[i]=l;
        ans+=l;
    }
    cout<<ans;
    system("pause");
    return 0;
}
