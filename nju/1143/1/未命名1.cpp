#include<cstdio>
#include<cstring>
int a[1000];
int b[1000][1000];
int main(){
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF){
        memset(b,127,sizeof(b));
        for(i=1;i<=n+1;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)b[i][i]=0;
        for(i=2;i<=n;i++)for(j=1;j<=n+1-i;j++)for(k=j;k<j+i-1;k++)if(b[j][j+i-1]>b[j][k]+b[k+1][j+i-1]+a[j]*a[k+1]*a[j+i])b[j][j+i-1]=b[j][k]+b[k+1][j+i-1]+a[j]*a[k+1]*a[j+i];
        printf("%d\n",b[1][n]);
    }
    return 0;
}
