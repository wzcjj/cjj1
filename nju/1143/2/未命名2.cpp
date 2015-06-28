#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> a;
int main(){
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF){
        while(!a.empty())a.pop();
        for(i=1;i<=n;i++){
            scanf("%d%d",&j,&k);
            a.push(-j);
        }
        long long ans=0;
        for(i=1;i<n;i++){
            int x,y,t;
            x=a.top();
            a.pop();
            y=a.top();
            a.pop();
            t=x+y;
            ans+=-t;
            a.push(t);
        }
        cout<<ans<<endl;
    }
    return 0;
}
        
