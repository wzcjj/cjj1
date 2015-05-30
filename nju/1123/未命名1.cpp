#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    bool a[2][22][80];
    int i,j,m,n;
    char c;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>n;
    for(i=0;i<22;i++){
        scanf("%c",&c);
        for(j=0;j<80;j++){
            scanf("%c",&c);
            if(c=='*')a[n%2][i][j]=true;
            else a[n%2][i][j]=false;
        }
    }
    while(n--){
        for(i=0;i<22;i++)for(j=0;j<80;j++){
            int cnt=0;
            for(int k=-1;k<=1;k++)for(int l=-1;l<=1;l++)if(a[1-n%2][(i+k+22)%22][(j+l+80)%80])cnt++;
            if(cnt==3||(cnt==4&&a[1-n%2][i][j]))a[n%2][i][j]=true;
            else a[n%2][i][j]=false;
        }    
    }
    for(i=0;i<22;i++){
        for(j=0;j<80;j++)if(a[0][i][j])printf("*");
        else printf(" ");
        printf("\n");
    }
    return 0;
}
