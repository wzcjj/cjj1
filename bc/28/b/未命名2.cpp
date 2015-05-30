#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[10000];
int main(){
    int T,i,j,m,n;
    cin>>T;
    a[0]=0;
    a[1]=1;
    for(i=2;a[i-1]<=1000000000;i++){
        a[i]=a[i-1]+a[i-2];
    }
    m=i;
    while(T--){
        scanf("%d",&n);
        int l,r,mid;
        l=0;
        r=m+1;
        int z=0;
        while(l<r-1){
            mid=(l+r)/2;
            if(a[mid]==n){
                printf("Yes\n");
                z=1;
                break;
            }
            else if(a[mid]<n)l=mid;
            else r=mid;
        }
        if(z==0)printf("No\n");
    }
    system("pause");
    return 0;
}
            
