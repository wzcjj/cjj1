#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct node{
    string s;
    int v;
}a[1005];
bool cmp(node x,node y)
{
    return x.v>y.v;
}
int main()
{
    int b[30];
    int i,j,m,n,k,l,z;
    int I,N;
    for(i=0;i<=2;i++)b[i]=2;
    for(i=3;i<=5;i++)b[i]=3;
    for(i=6;i<=8;i++)b[i]=4;
    for(i=9;i<=11;i++)b[i]=5;
    for(i=12;i<=14;i++)b[i]=6;
    for(i=15;i<=18;i++)b[i]=7;
    for(i=19;i<=21;i++)b[i]=8;
    for(i=22;i<=25;i++)b[i]=9;
    string s;
    cin>>N;
    for(I=1;I<=N;I++)
    {
        printf("Scenario #%d:\n",I);
        cin>>n;
        for(i=1;i<=n;i++)cin>>a[i].s>>a[i].v;
        sort(a+1,a+n+1,cmp);
        /*cout<<"<";
        for(i=1;i<=n;i++)cout<<a[i].s<<" "<<a[i].v<<endl;
        cout<<">"; */
        cin>>m;
        for(i=1;i<=m;i++)
        {
            cin>>s;
            k=1;
            for(j=0;j<s.length()-1;j++)
            {
                for(;k<=n;k++)
                {
                    z=0;
                    for(l=0;l<=j;l++)if(s[l]-'0'!=b[a[k].s[l]-'a']){z=1;break;}
                    if(z==0)break;
                }
                if(z)cout<<"MANUALLY"<<endl;
                else 
                {
                    for(l=0;l<=j;l++)cout<<a[k].s[l];
                    cout<<endl;
                }
            }
            cout<<endl; 
        }
        cout<<endl;
    }
    return 0;
}
            
