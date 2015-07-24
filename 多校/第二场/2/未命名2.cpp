#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int main(){
    int i,j,m,n,x,y;
    while(cin>>n>>m>>x>>y){
        int ans=1;
        if(!(n%2==1&&m%2==1&&x==n/2+1&&y==m/2+1))ans=min((n+1)/2,(m+1)/2);
        if(x>1){
            int t=min(min(x-1,y),m-y+1);
            if(ans<t)ans=t;
        }
        if(x<n){
            int t=min(min(n-x,y),m-y+1);
            if(ans<t)ans=t;
        }
        if(y>1){
            int t=min(min(y-1,x),n-x+1);
            if(ans<t)ans=t;
        }
        if(y<m){
            int t=min(min(m-y,x),n-x+1);
            if(ans<t)ans=t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
