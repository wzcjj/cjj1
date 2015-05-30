#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;
long long a[100005],m;
int b[50];
bool cmp(){
    long long t=0;
    for(int i=0;i<=31;i++)if(b[i])t+=(1<<i);
    return t<m;
}
int main()
{
    int i,j,n,N;
    cin>>N;
    for(int I=1;I<=N;I++){
        cin>>n>>m;
        for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
        j=1;
        memset(b,0,sizeof(b));
        for(int k=0;(1<<k)<=a[1];k++)if((1<<k)&a[1])b[k]++;
        long long ans=0;
        for(i=1;i<=n;i++){
            while(j<=n&&cmp()){
                j++;
                for(int k=0;(1<<k)<=a[j];k++)if((1<<k)&a[j])b[k]++;
            }
            ans+=j-i;
            for(int k=0;(1<<k)<=a[i];k++)if((1<<k)&a[i])b[k]--;
        }
        printf("Case #%d: %I64d\n",I,ans);
    }
    return 0;
}
        
        
