#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int a[10005],b[1005],c[1005];
int main(){
    int i,j,m,n,N;
    printf("Case #1:\n");
    memset(b,0,sizeof(b));
    cin>>n>>m;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        int l,r;
        l=r=a[i];
        b[1]++;
        memset(c,0,sizeof(c));
        c[1]=a[i];
        c[0]=1;
        for(j=i+1;j<=i+1000;j++){
            if(j>n)break;
            c[++c[0]]=a[j];
            if(a[j]>r){
                r=a[j];
            }
            else if(a[j]<l){
                l=a[j];
            }
                if(r-l==j-i){
                    sort(c+1,c+c[0]+1);
                    bool flag=true;
                    for(int k=1;k<c[0];k++)if(c[k]==c[k+1]){
                        flag=false;
                        break;
                    }
                    if(flag)b[j-i+1]++;
                }
            
        }
    }
    for(i=1;i<=m;i++){
        scanf("%d",&j);
        printf("%d\n",b[j]);
    }
    return 0;
}
