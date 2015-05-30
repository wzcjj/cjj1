#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a[2005][2005];
int main(){
    int i,j,m,n,I,N,o,k;
    cin>>N;
    for(I=1;I<=N;I++){
        cin>>n>>m>>o;
        string s;
        cin>>s;
        a[2*n][0]=1;
        for(i=1;i<=m;i++)a[2*n][i]=0;
        for(i=2*n-1;i>=1;i--){
            a[i][0]=1;
            int b1,b0,bb;
            b1=b0=bb=0;
            for(j=1;j<=m;j++){
                if(a[i+1][j-1]==1)b1++;
                else if(a[i+1][j-1]==0)b0++;
                else bb++;
                if(j-o>0){
                    if(a[i+1][j-1-o]==1)b1--;
                    else if(a[i+1][j-1-o]==0)b0--;
                    else bb--;
                }
                if(s[i-1]==s[i]){
                    if(b1>0)a[i][j]=1;
                    else if(b0>0)a[i][j]=0;
                    else a[i][j]=-1;
                } 
                else{
                    if(b1>0)a[i][j]=-1;
                    else if(b0>0)a[i][j]=0;
                    else a[i][j]=1;
                }
            }
        }
        int z=0;
        cout<<"Case #"<<I<<": ";
        for(j=m-o;j<=m-1;j++)if(a[1][j]==1){
            cout<<s[0]<<endl;
            z=1;
            break;
        }
        if(z==0) cout<<(char)('B'-s[0]+'A')<<endl;
    }
    system("pause");
    return 0;
}


