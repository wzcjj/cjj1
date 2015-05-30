#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[40];
long long mo(long long x,long long y,long long p){
    double t;
    t=x;
    t*=y;
    t-=((int)(t/p+0.00000001))*p;
    return (int)(t+0.00000001);
} 
int main(){
    long long i,j;
    long long n,m;
    while(cin>>n>>m){
        a[0]=2;
        for(i=1;i<=35;i++)a[i]=mo(a[i-1],a[i-1],m);
        long long ans=1;
        i=(int)(log(n)/log(2)+0.1);
        while(i>=0&&n>0){
            if((1<<i)<=n){
                ans=mo(ans,a[i],m);
                n-=1<<i;
            }
            i--;
        }
        cout<<(ans-2+m)%m<<endl;
    }
    return 0;
}
