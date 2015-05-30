#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[5],k[5];
int main(){
    long long i,j,m,n;
    int N,I;
    cin>>N;
    for(I=1;I<=N;I++){
        cin>>n>>k[1]>>k[2]>>k[3];
        long long l=0,r=n+1,mid;
        while(l<r-1){
            mid=(l+r)/2;
            if(mid*k[1]>n-mid)r=mid;
            else if(mid*k[1]<n-mid)l=mid;
            else{
                a[1]=mid;
                break;
            }
        }
        l=a[1],r=n+1;
        while(l<r-1){
            mid=(l+r)/2;
            if((mid-a[1])*k[2]>n-mid+a[1])r=mid;
            else if((mid-a[1])*k[2]<n-mid+a[1])l=mid;
            else{
                a[2]=mid-a[1];
                break;
            }
        }
        l=a[1]+a[2],r=n+1;
        while(l<r-1){
            mid=(l+r)/2;
            if((mid-a[1]-a[2])*k[3]>n-mid+a[1]+a[2])r=mid;
            else if((mid-a[1]-a[2])*k[3]<n-mid+a[1]+a[2])l=mid;
            else{
                a[3]=mid-a[1]-a[2];
                break;
            }
        }
        a[4]=n-a[1]-a[2]-a[3];
        printf("Case #%d: %d %d %d %d\n",I,a[1],a[2],a[3],a[4]);
    }
    return 0;
}
