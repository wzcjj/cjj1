#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[5][5];
int max(int x){
    int i,j;
    for(i=1;i<=3;i++)for(j=i+1;j<=3;j++)if(a[x][i]<a[x][j]){
        int t=a[x][i];
        a[x][i]=a[x][j];
        a[x][j]=t;
    }
    return a[x][1];
}
struct node{
    int v,i;
}b[5];
bool cmp(node x,node y){
    return x.v>y.v;
}
int c[5];
int main(){
    int i,j,m,n; 
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>m;
        for(j=1;j<=m;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
            b[j].v=max(j);
            b[j].i=j;
        }
        sort(b+1,b+m+1,cmp);
        for(j=1;j<=m;j++)c[b[j].i]=j;
        for(j=1;j<=m;j++){
            cout<<c[j];
            if(j==m)cout<<endl;
            else cout<<' ';
    }
    system("pause");
    return 0;
}
        
