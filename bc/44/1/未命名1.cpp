#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int c[5]={0,1000,1500,2000,2500};
int main(){
    int i,j,m,n,I=0,N,a,b;
    cin>>N;
    while(N--){
        I++;
        printf("Case #%d: ",I);
        long long ans=0;
        for(i=1;i<=4;i++){
            cin>>a>>b;
            long long t=(250-a)*c[i]/250-b*50;
            ans+=t>c[i]/10*4?t:c[i]/10*4;
        }
        cout<<ans<<endl;
    }
    return 0;
}
