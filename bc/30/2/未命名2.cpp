#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
long long n,m;
long long a[10005];
struct node{
    long long num,many;
}b[105];
long long c[10005];
void calc(int x,long long t){
    if(x>m){
        n++;
        a[n]=t;
        return;
    }
    for(int i=0;i<b[x].many;i++){
        calc(x+1,t);
        t*=b[x].num;
    }
    calc(x+1,t);
}
long long gcd(long long x,long long y){
    if(y==0)return x;
    return gcd(y,x%y);
}
int main(){
    int i,j;
    int I=0;
    while(scanf("%lld",&n)!=EOF){
        I++;
        memset(a,0,sizeof(a));
        long long N=n;
        m=0;
        for(i=2;i*i<=n;i++)if(n%i==0){
            m++;
            b[m].num=i;
            b[m].many=0;
            while(n%i==0){
                b[m].many++;
                n=n/i;
            }
        }
        if(n>1){
            m++;
            b[m].num=n;
            b[m].many=1;
        }
        n=0;
        calc(1,1);
        sort(a+1,a+1+n);
        printf("Case #%d:\n",I);
        int ans=0;
        for(i=1;i<n;i++)if(((a[i]^N)<=N)&&(gcd(N,a[i]^N)==a[i])){
            ans++;
            c[ans]=a[i]^N;
        }
        sort(c+1,c+1+ans);
        printf("%d\n",ans);
        for(i=1;i<=ans-1;i++)printf("%lld ",c[i]);
        if(ans)printf("%lld\n",c[ans]);
        else printf("\n");
    }
    return 0;
}
