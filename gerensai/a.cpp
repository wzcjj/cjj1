#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std; 
vector<int> a;
bool prime[10000005];
int min(int x,int y){
    return x<y?x:y;
}
int main(){
    int i,j,m,n,x,y;
    cin>>n;
    for(i=2;i<=10000000;i++)prime[i]=true;
    for(i=2;i<=10000000;i++)if(prime[i])
    {
        a.push_back(i);
        for(j=2;j<=10000000/i;j++)prime[i*j]=false;
    }
    for(int I=1;I<=n;I++){
        cin>>x>>y;
        long long ans=0;
        for(i=0;a[i]<=min(x,y);i++){
            ans+=y/a[i];
            for(j=2;j<=x/a[i];j++){ans+=y/a[i]-y/a[i]/j;
            cout<<ans<<' ';}
        }
        cout<<ans<<endl;
    }
    return 0;
}
