#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <cmath>
using namespace std;
unsigned a[1005][5],b[55][5],c[1005],d[55],e[1005];
int main(){
    int i,j,m,n,I,N;
    cin>>N;
    for(I=1;I<=N;I++){
        cin>>n>>m;
        printf("Case #%d:\n",I);
        for(i=1;i<=n;i++){scanf("%d.%d.%d.%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4]);c[i]=a[i][1]*256*256*256+a[i][2]*256*256+a[i][3]*256+a[i][4];}
        for(i=1;i<=m;i++){scanf("%d.%d.%d.%d",&b[i][1],&b[i][2],&b[i][3],&b[i][4]);d[i]=b[i][1]*256*256*256+b[i][2]*256*256+b[i][3]*256+b[i][4];}
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                e[j]=c[j]&d[i];
            }
            sort(e+1,e+1+n);
            int ans=0;
            for(j=1;j<=n;j++){
                ans++;
                while(j<n&&e[j]==e[j+1])j++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
