#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
map<int,int> c;
int main()
{
    int a[70],b[70];
    int i,j,m=0,n=0,z;
    scanf("%d",&i);
    while(i!=-1)
    {
        a[++m]=i;
        c[i]=1;
        scanf("%d",&i);
    }
    scanf("%d",&i);
    while(i!=-1)
    {
        b[++n]=i;
        if(c[i]==1)c[i]=2;
        scanf("%d",&i);
    }
    z=0;
    for(i=1;i<=m;i++)if(c[a[i]]==2)
    {
        if(z==0)
        {
            cout<<a[i];
            z=1;
        }
        else cout<<' '<<a[i];
    }
    cout<<endl;
    z=0;
    for(i=1;i<=m;i++)if(z==0)
    {
        cout<<a[i];
        z=1;
    }
    else cout<<' '<<a[i];
    for(i=1;i<=n;i++)if(c[b[i]]!=2)
    {
        if(z==0)
        {
            cout<<b[i];
            z=1;
        }
        else cout<<' '<<b[i];
    }
    cout<<endl;
    z=0;
    for(i=1;i<=m;i++)if(c[a[i]]!=2)
    {
        if(z==0)
        {
            cout<<a[i];
            z=1;
        }
        else cout<<' '<<a[i];
    }
    cout<<endl;
    if(z)cout<<"false";
    else cout<<"true";
    cout<<endl;
    system("pause");
    return 0;
}
