#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#define P 1000000007
#define maxN 105
using namespace std;
long long a[maxN],b[maxN],c[maxN];
int main(){
    int i,j,m,n;
    c[0]=1;
    for(i=1;i<=100;i++)c[i]=c[i-1]*i%P;
    b[0]=0;
    for(i=1;i<=100;i++)b[i]=(b[i-1]*i+(i-1)*i/2*c[i-1])%P;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        long long t=0,ans=0;
        for(i=n;i>=1;i--){
            int s=0;
            for(j=i+1;j<=n;j++)if(a[i]>a[j])s++;
            ans= (ans+t*s+b[n-i]*s+c[n-i]*s*(s-1)/2)%P;
            t = (t+c[n-i]*s)%P;
        }
        cout<<ans<<endl;
    }
    return 0;
}
        
        
