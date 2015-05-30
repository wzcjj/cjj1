#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a[20][5];
    int b[5];
    int i,j,m,n,t=0;
    int min;
    for(i=1;i<=16;i++)for(j=1;j<=3;j++)cin>>a[i][j];
    while(1)
    {
        for(i=1;i<=3;i++)cin>>b[i];
        if(b[1]==-1)break;
        min=2000000000;
        for(i=1;i<=16;i++)
        {
            int ans=0;
            for(j=1;j<=3;j++)ans+=(b[j]-a[i][j])*(b[j]-a[i][j]);
            if(ans<min)
            {
                t=i;
                min=ans;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",b[1],b[2],b[3],a[t][1],a[t][2],a[t][3]);
    }
    return 0;
}
