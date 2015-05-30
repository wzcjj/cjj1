#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std; 
bool a[105][105][105];
int main(){
    int i,j,m,n,x,y,z,q,k,l,ans;
    cin>>n>>m;
    memset(a,false,sizeof(a));
    for(i=1;i<=m;i++){
        cin>>x>>y>>z;
        a[x][y][z]=true;
        a[y][x][z]=true;
    }
    cin>>q;
    for(i=1;i<=q;i++){
        cin>>x>>y;
        ans=0;
        for(j=1;j<=m;j++){
            z=0;
            while(z==0){
                z=1;
                for(k=1;k<=n;k++){
                    if(a[x][k][j])for(l=1;l<=n;l++){
                        if(a[k][l][j]&&!a[x][l][j]){
                            a[x][l][j]=true;
                            a[l][x][j]=true;
                            z=0;
                        }
                    }
                }
            }
            if(a[x][y][j])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
                            
                        
