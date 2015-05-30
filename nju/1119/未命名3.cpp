#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
using namespace std;
map<int,int> c;
int main()
{
    bool a[70][70];
    int b[70];
    int i,j,m,n=0,x,y,z,k;
    memset(a,false,sizeof(a));
    cin>>i;
    while(i!=-1)
    {
        if(c.find(i)==c.end())
        {
            b[++n]=i;
            c[i]=n;
        }
        cin>>i;
    }
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[c[x]][c[y]]=true;
    }
    z=0;
    for(i=1;i<=n;i++)if(!a[i][i])z=1;
    if(z==0)cout<<"reflexive"<<endl;
    z=0;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i][j]!=a[j][i])z=1;
    if(z==0)cout<<"symmetric"<<endl;
    z=0;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(k=1;k<=n;k++)if(((a[i][j]&&a[j][k])==true)&&(a[i][k]==false))z=1;
    if(z==0)cout<<"transitive"<<endl;
    system("pause");
    return 0;
}
