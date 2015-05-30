#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int a,b,i;
}c[105];
bool cmp(node x,node y){
    if(x.a-x.b>y.a-y.b)return true;
    else if(x.a-x.b<y.a-y.b)return false;
    else return x.b<=y.b;
}
int main(){
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            cin>>c[i].a>>c[i].b;
            c[i].i=i;
        }
        for(i=0;i<n;i++)for(j=n-2;j>=i;j--)if(!cmp(c[j],c[j+1])){
            node t=c[j];
            c[j]=c[j+1];
            c[j+1]=t;
        }
        for(i=0;i<n-1;i++)cout<<c[i].i<<' ';
        cout<<c[n-1].i<<endl;
    }
    return 0;
}
