#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
long long a[100005];
int main(){
    int i,j,m,n;
    while(cin>>n>>m){
        for(i=1;i<=n;i++)scanf("%I64d",&a[i]); 
        for(i=1;i<=n;i++)a[i]%=m;
        sort(a+1,a+n+1);
        long long ans=(a[n]+a[n-1])%m;
        j=n;
        for(i=1;i<=n;i++){
            while(j>=i&&a[i]+a[j]>=m)j--;
            if(j<i)break;
            if(ans<a[i]+a[j])ans=a[i]+a[j];
        }
        cout<<ans<<endl;
    }
    return 0;
}
        
