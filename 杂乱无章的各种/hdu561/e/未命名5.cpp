#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int a[50005];
int main(){
    int i,j,m,n,I,N,q;
    cin>>N;
    for(I=1;I<=N;I++){
        cin>>n>>m>>q;
        memset(a,0,sizeof(a));
        printf("Case #%d:\n",I);
        for(i=1;i<=q;i++){
            int t,l;
            scanf("%d%d",&t,&l);
            for(j=1;j<=n;j++)if(a[j]<=t){
                a[j]=t+l+m;
                printf("%d\n",j);
                break;
            }
            if(j==n+1)printf("Failed!\n");
        }
    }
    system("pause");
    return 0;
}
