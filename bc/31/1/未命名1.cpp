#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
    int i,j,m,n;
    int N;
    cin>>N;
    while(N--){
        cin>>n>>m;
        for(i=1;i<=n;i++)scanf("%d",&a[i]); 
        sort(a+1,a+n+1);
        long long ans=0;
        int x,y;
        y=2;
        for(x=1;x<n;x++){
            while(y<=n&&a[y]-a[x]<=m)y++;
            ans+=y-x-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
