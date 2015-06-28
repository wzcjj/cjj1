#include<cstdio>
#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;
bool a[500][500];
int fa[250000];
int getfa(int x){
    if(fa[x]!=x)fa[x]=getfa(fa[x]);
    return fa[x];
}
int main(int argc,char* argv[]){
    int i,j,m,n,k;
    srand(unsigned(time(0)));
    if(argc==1){
        cin>>n>>m;
        cout<<n<<' '<<m<<endl;
        return 0;
    }
    else if(argc==2&&strcmp(argv[1],"test")==0){
        cin>>n>>m;
        memset(a,false,sizeof(a));
        for(i=0;i<=m;i++)a[0][2*i]=true;
        a[1][0]=a[n][2*m]=true;
        for(i=1;i<=n;i++)for(j=1;j<=m;j++)fa[i*(m+1)+j]=i*(m+1)+j;
        int sum=n*m;
        while(sum>1){
            i=rand()%n+1;
            j=rand()%m+1;
            k=rand()%2;
            if(k==1){
                if(i<n&&getfa(i*(m+1)+j)!=getfa((i+1)*(m+1)+j)){
                    a[i][2*j-1]=true;
                    fa[getfa(i*(m+1)+j)]=getfa((i+1)*(m+1)+j);
                    sum--;
                }
            }
            else{
                if(j<m&&getfa(i*(m+1)+j)!=getfa((i)*(m+1)+j+1)){
                    a[i][2*j]=true;
                    fa[getfa(i*(m+1)+j)]=getfa((i)*(m+1)+j+1);
                    sum--;
                }
            }
        }
        for(i=0;i<=n;i++){
            for(j=0;j<=2*m;j++){
                if(!a[i][j]){
                    if(j%2)printf("_");
                    else printf("|");
                }
                else printf(" ");
            }
            printf("\n");
        } 
    }
    return 0;
}
