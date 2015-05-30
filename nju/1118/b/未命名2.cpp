#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<int,int> c;
vector<int> a,b;
int main()
{
    int i,j,m=0,n=0,z;
    a.push_back(0);
    b.push_back(0);
    cin>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&j);
        c[j]=1;
        a.push_back(j);
    }
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&j);
        if(c[j]==1)c[j]=2;
        b.push_back(j);
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
