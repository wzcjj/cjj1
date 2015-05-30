#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a(int size,int small){
    if(small%2==1&&size%2==1){
        return small-1;
    }
    if(small%2==0&&size%2==1){
        return small;
    }
    if(small%2==1&&size%2==0){
        return small;
    }
    if(small%2==0&&size%2==0){
        return small-1;
    }
}
int main(){
    int i,j,m,n;
    long long ans;
    while(cin>>n>>m){
        int max=-1,min=n+1;
        for(i=1;i<=m;i++){
            cin>>j;
            if(j>max)max=j;
            if(j<min)min=j;
        }
        if(max==n){
            ans=0;
            for(i=1;i<=min/2-1;i++)ans+=a(min-1-i,i);
            cout<<ans<<endl;
        }
        else if(min==1){
            ans=0;
            for(i=1;i<=(n-max+1)/2-1;i++)ans+=a(n-max-i,i);
            cout<<ans<<endl;
        }
        else if(n-max>min-1){
            ans=a(n-max,min-1);
            cout<<ans<<endl;
        }
        else if(n-max<min-1){
            ans=a(min-1,n-max);
            cout<<ans<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}
            
        
