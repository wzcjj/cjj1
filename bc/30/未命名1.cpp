#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
long long a[105];
int main(){
    long long right[105];
    int i,j,m,n;
    int I=0;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        I++;
        for(i=1;i<=n;i++)scanf("%lld",&a[i]);
        sort(a+1,a+1+n);
        for(i=1;i<=n;i++)right[i]=i+1;
        for(i=1;i<=n;i=right[i])while(a[i]==a[right[i]])right[i]++;
        if(right[1]==n+1){
            printf("Case #%d: -1\n",I);
            continue;
        }
        for(i=1;i<=n;i=right[i])if((a[i]+a[(right[i]-1)%n+1])%2147483647==a[(right[(right[i]-1)%n+1]-1)%n+1])ans+=right[right[i]]-right[i];
        printf("Case #%d: %d\n",I,ans);
    }
    return 0;
}
            
