#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define P 998244353
using namespace std;
long long a[100005],b[100005];
long long c[70],d[70],e[70];
int main(){
    int i,j,m,n,I=0,N;
    cin>>N;
    while(N--){
        I++;
        printf("Case #%d: ",I);
        cin>>n;
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        memset(e,0,sizeof(e));
        for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
        for(i=1;i<=n;i++)scanf("%I64d",&b[i]);
        for(i=0;i<=60;i++)for(j=1;j<=n;j++)if((a[j]&(1<<i)))c[i]++;
        for(i=0;i<=60;i++)for(j=1;j<=n;j++)if((b[j]&(1<<i)))d[i]++;
        for(i=0;i<=60;i++){
            e[i]+=c[i]*(n-d[i])+d[i]*(n-c[i]);
            e[i+1]+=c[i]*d[i];
        }
        long long ans=0;
        for(i=0;i<=60;i++)if(e[i]%2)ans+=(1<<i);
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}
