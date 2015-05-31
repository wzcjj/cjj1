#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
    int i,j,m,n,N;
    cin>>N;
    int I=0;
    while(N--){
        I++;
        printf("Case #%d:\n",I);
        cin>>n;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        b[1]=0;
        c[1]=a[1];
        for(i=2;i<=n;i++){
            if(a[i]>c[i-1]){
                b[i]=b[i-1];
                c[i]=max(a[i]-b[i],c[i-1]+1);
            }
            else{
                if(c[i-1]+1-a[i]<=b[i-1]){
                    b[i]=b[i-1];
                    c[i]=c[i-1]+1;
                }
                else{
                    b[i]=b[i-1]+(c[i-1]+2-a[i]-b[i-1])/2;
                    c[i]=a[i]+b[i];
                    if((c[i-1]+1-a[i]-b[i-1])%2==1)c[i]--;
                }
            }
        }
        cout<<b[n]<<endl;
    }
    return 0;
}
