#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100];
int main(){
    int i,j,m;
    long long n;
    int I,N;
    cin>>N;
    while(N--){
        I++;
        cin>>n;
        for(i=0;(1LL<<i)<=n;i++){
            if((1LL<<i)&n)a[i]=1;
            else a[i]=0;
        }
        int ans=0;
        if(a[0])ans++;
        for(i=1;(1LL<<i)<=n;i++)if(a[i]==1&&a[i-1]==0)ans++;
        cout<<ans<<endl;
    }
    return 0;
} 
