#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define P 998244353
using namespace std;
long long a[50005];
bool cmp(long long x,long long y){
    if(y==0)return true;
    if(x==0)return false;
    for(int i=0;i<=30;i++){
        long long a=(1LL<<i)&x;
        long long b=(1LL<<i)&y;
        if(a==b)continue;
        return a>b;
    }
}
long long calc(int l,int r,int p){
    if(r<=l||p>=30)return 0;
    int x=l-1,y=r+1;
    while(x<y-1){
        int mid=(x+y)>>1;
        if(a[mid]&(1LL<<p))x=mid;
        else y=mid;
    }
    long long ans=(long long)2*(x-l+1)*(r-y+1)*(1LL<<p)%P;
        ans=(ans+calc(l,x,p+1))%P;
        ans=(ans+calc(y,r,p+1))%P;
    return ans;
}
int main(){
    int i,j,m,n,I=0,N;
    cin>>N;
    while(N--){
        I++;
        printf("Case #%d: ",I);
        cin>>n;
        for(i=1;i<=n;i++)scanf("%lld",&a[i]);
        sort(a+1,a+1+n,cmp);
        long long ans=calc(1,n,0);
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}
        
