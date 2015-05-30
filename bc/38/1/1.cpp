#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,m,n;
    long long x[5],y[5],z[5]; 
    cin>>n;
    for(int I=1;I<=n;I++)
    {
        int sumx=0,sumy=0,sumz=0;
        for(i=1;i<=4;i++){
        cin>>x[i]>>y[i]>>z[i];
        sumx+=x[i];
        sumy+=y[i];
        sumz+=z[i];}
        int t=0;
        for(i=1;i<=3;i++)if(t==0)for(j=i+1;j<=4;j++)if((x[i]+x[j])*2==sumx&&(y[i]+y[j])*2==sumy&&(z[i]+z[j])*2==sumz)
        {
            if(!((x[2]-x[1])*(x[3]-x[1])+(y[2]-y[1])*(y[3]-y[1])+(z[2]-z[1])*(z[3]-z[1])==0&&(x[2]-x[4])*(x[3]-x[4])+(y[2]-y[4])*(y[3]-y[4])+(z[2]-z[4])*(z[3]-z[4])==0||
            (x[2]-x[1])*(x[4]-x[1])+(y[2]-y[1])*(y[4]-y[1])+(z[2]-z[1])*(z[4]-z[1])==0&&(x[2]-x[3])*(x[4]-x[3])+(y[2]-y[3])*(y[4]-y[3])+(z[2]-z[3])*(z[4]-z[3])==0||
            (x[4]-x[1])*(x[3]-x[1])+(y[4]-y[1])*(y[3]-y[1])+(z[4]-z[1])*(z[3]-z[1])==0&&(x[4]-x[2])*(x[3]-x[2])+(y[4]-y[2])*(y[3]-y[2])+(z[4]-z[2])*(z[3]-z[2])==0))continue;
            t=1;
            printf("Case #%d: Yes\n",I);
            break;
        }
        if(t==0)printf("Case #%d: No\n",I);
    }
    return 0;
}
