#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct node{
    string s;
    int v;
}a[205];
bool cmp(node x,node y){
    if(x.v>y.v)return true;
    else if(x.v<y.v)return false;
    else return x.s<y.s;
}
int main(){
    int i,j,m,n,k;
    while(cin>>n){
        if(n==0)break;
        for(i=1;i<=n;i++)cin>>a[i].s>>a[i].v;
        sort(a+1,a+1+n,cmp);
        for(i=1;i<=n;i++)cout<<a[i].s<<' '<<a[i].v<<endl;
        cin>>m;
        for(i=1;i<=m;i++){
            string s;
            cin>>s;
            for(j=1;j<=n;j++)if(a[j].s==s)break;
            for(k=j;k>=1;k--)if(a[j].v!=a[k].v)break;
            cout<<k+1;
            if(j-k>1)cout<<' '<<j-k;
            cout<<endl;
        }
    }
    return 0;
}
         
