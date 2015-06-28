#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1005];
int b[1005][1005];
int main(){
    int i,j,m;
    long long n;
    int I,N;
    memset(b,0,sizeof(b));
        cin>>n>>m;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++){
            for(j=1;j<i;j++)if(a[i]<a[j])b[i][j]=b[i][j-1]+1;
            else b[i][j]=b[i][j-1];
        }
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            long long ans=0;
            for(j=x;j<=y;j++)ans+=b[j][j-1]-b[j][x-1];
            printf("%I64d\n",ans);
        }
    return 0;
}
