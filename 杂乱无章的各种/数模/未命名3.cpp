#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#define maxn 10
using namespace std;
struct node{
    int ans,x,y;
}a[maxn][1000];
int pow[maxn];
int out[maxn][2];
int main(){
    int i,j,m,n,k;
    cin>>n;
    pow[0]=1;
    for(i=1;i<maxn;i++)pow[i]=pow[i-1]*3;
    for(i=0;pow[i]<=n;i++);
    m=i;
    for(i=1;i<=2;i++){
        a[1][i].ans=1;
        a[1][i].x=1;
        a[1][i].y=2;
    }
    for(i=2;i<=m;i++){
        for(j=2*i+1;j<=pow[i];j++){
            int ans=10000;
            int ansi;
            for(k=2*i-1;k<=min(pow[i-1],j-2);k++)if(a[i-1][k-1].ans){
                int sum=max((j-k)/2,a[i-1][k-1].ans*(2+(j-k>2)));
                if(ans>sum){
                    ans=sum;
                    ansi=k;
                }
            }
            a[i][j].ans=ans;
            a[i][j].x=ansi;
            a[i][j].y=ansi+(j-ansi)/2;
        }
    }
    int t=n;
    for(i=m;i>=1;i--){
        out[i][0]=a[i][t].x;
        out[i][1]=a[i][t].y;
        t=a[i][t].x-1;
    }
    for(i=1;i<=m;i++)cout<<out[i][0]<<' '<<out[i][1]<<endl;
    cout<<a[m][n].ans<<endl;
    system("pause");
    return 0;
}
            
