#include <iostream>
#include<string>
#include <cstring>
using namespace std;
#define max 100000
int l[max],r[max],p[max],v[max],b[max];
string c[max];
int root,m,s;
void fixup(int z);
void insert(int z)
{
    int x,y;
    y=0;
    x=root;
    while (v[x]!=0)
    {
        y=x;
        if (v[z]<v[x]) x=l[x];
        else x=r[x];
    }
    p[z]=y;
   
    if (y==0) root=z;
    else if (v[z]<v[y]) l[y]=z;
    else r[y]=z;
    l[z]=0;
    r[z]=0;
    c[z]="red";
    fixup(z);
    
    
}
void leftrotate(int x)
{
    int y;
    y=r[x];
    r[x]=l[y];
    
    if (v[y]!=0)
    {
       p[l[y]]=x;

    }
    p[y]=p[x];
    if (p[x]==0)
    {
        root=y;
    }
    else if (x==l[p[x]])
    {
        l[p[x]]=y;
    }
    else
    {
    r[p[x]]=y;
    
    }
    l[y]=x;
    p[x]=y;

}
void rightrotate(int x)
{
    int y;
    y=l[x];
    l[x]=r[y];
    if (v[y]!=0)
        p[r[y]]=x;
    p[y]=p[x];
    if (p[x]==0)
        root=y;
    else if (x==l[p[x]])
        l[p[x]]=y;
    else r[p[x]]=y;
    r[y]=x;
    p[x]=y;
    
}

void fixup(int z)
{
    int y;
    while (p[z]!=0&&c[p[z]]=="red")
    {
        
        if (p[z]==l[p[p[z]]])
        {

            y=r[p[p[z]]];
            
            if (c[y]=="red")
            {
                c[p[z]]="black";
                c[y]="black";
                c[p[p[z]]]="red";
                z=p[p[z]];
            }
            else if(z==r[p[z]])
            {
                z=p[z];
                leftrotate(z);
            }
            else
            {
                c[p[z]]="black";
                c[p[p[z]]]="red";
                rightrotate(p[p[z]]);
            }
            
        }
        else if (p[z]==r[p[p[z]]])
        {
            
            y=l[p[p[z]]];
            if (c[y]=="red")
            {
                c[p[z]]="black";
                c[y]="black";
                c[p[p[z]]]="red";
                z=p[p[z]];
            }
            else if(z==l[p[z]])// exchange all left with right?
            {
                z=p[z];
                rightrotate(z);
            }
            else
            {
                c[p[z]]="black";
                c[p[p[z]]]="red";
                leftrotate(p[p[z]]);
            }
            
        }

    }
  c[root]="black";
}
void search(int t,int x)
{
    if ((v[t]==x)||t==0) return;
    else if (x<v[t])
    {
        s++;
        search(l[t],x);
    }
    else
    {
        s++;
        search(r[t],x);
    }
}
void print(int x)
{
    if ((x>=1)&&(x<=m))
    {
        cout<<v[x]<<':'<<c[x]<<endl;
        print(l[x]);
        print(r[x]);
    }
    else return;
}
int main(int argc, const char * argv[]) {
    int n,i,j;
    while (cin>>m>>n)
    { for (i=1;i<=m;++i)cin>>v[i];
    for (j=1;j<=n;++j)cin>>b[j];
    root=1;
  
    v[0]=0;
    l[1]=0;
    r[1]=0;
    for (i=2;i<=m;++i)
    {
        l[i]=0;
        r[i]=0;
        p[i]=0;
        insert(i);
    }
    for (i=1;i<=m;++i)cout <<l[i]<<' '<<r[i]<<endl;
      //  cout<<1<<endl;
    print (root);
           for (i=1;i<=n;++i)
    {
        s=0;
        search (root,b[i]);
        cout<<s<<endl;
    }
    }
    return 0;
}
